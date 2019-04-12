#include "huffman.h"
#include <iostream>
#include "assert.h"

void create_tree (

    /* input */ Symbol in[INPUT_SYMBOL_SIZE],

    /* input */ int num_symbols,

    /* output */ ap_uint<SYMBOL_BITS> parent[INPUT_SYMBOL_SIZE-1],

    /* output */ ap_uint<SYMBOL_BITS> left[INPUT_SYMBOL_SIZE-1],

    /* output */ ap_uint<SYMBOL_BITS> right[INPUT_SYMBOL_SIZE-1]) {

    Frequency frequency[INPUT_SYMBOL_SIZE-1];

    ap_uint<SYMBOL_BITS> tree_count = 0;  // Number of intermediate nodes assigned a parent.

    ap_uint<SYMBOL_BITS> in_count = 0;    // Number of inputs consumed.

    assert(num_symbols > 0);

    assert(num_symbols <= INPUT_SYMBOL_SIZE);

    for(int i = 0; i < (num_symbols-1); i++) {

        #pragma HLS PIPELINE II=5

        Frequency node_freq = 0;

        // There are two cases.

        // Case 1: remove a Symbol from in[]

        // Case 2: remove an element from intermediate[]

        // We do this twice, once for the left and once for the right of the new intermediate node.

        assert(in_count < num_symbols || tree_count < i);

        Frequency intermediate_freq = frequency[tree_count];

        Symbol s = in[in_count];

        if((in_count < num_symbols && s.frequency <= intermediate_freq) || tree_count == i) {

            // Pick symbol from in[].

            left[i] = s.value; // Set input symbol as left node

            node_freq = s.frequency; // Add symbol frequency to total node frequency

            in_count++; // Move to the next input symbol

        } else {

            // Pick internal node without a parent.

            left[i] = INTERNAL_NODE; // Set symbol to indicate an internal node

            node_freq = frequency[tree_count]; // Add child node frequency

            parent[tree_count] = i; // Set this node as child's parent

            tree_count++; // Go to next parentless internal node

        }

        assert(in_count < num_symbols || tree_count < i);

        intermediate_freq = frequency[tree_count];

        s = in[in_count];

        if((in_count < num_symbols && s.frequency <= intermediate_freq) || tree_count == i) {

            // Pick symbol from in[].

            right[i] = s.value;

            frequency[i] = node_freq + s.frequency;

            in_count++;

        } else {

            // Pick internal node without a parent.

            right[i] = INTERNAL_NODE;

            frequency[i] = node_freq + intermediate_freq;

            parent[tree_count] = i;

            tree_count++;
        }

        // Verify that nodes in the tree are sorted by frequency

        assert(i == 0 || frequency[i] >= frequency[i-1]);
    }

    parent[tree_count] = 0; //Set parent of last node (root) to 0
}

//functions

// Postcondition: out[x].frequency > 0

void filter(

            /* input  */ Symbol in[INPUT_SYMBOL_SIZE],

            /* output */ Symbol out[INPUT_SYMBOL_SIZE],

            /* output */ int *n) {

    #pragma HLS INLINE off

    ap_uint<SYMBOL_BITS> j = 0;

    for(int i = 0; i < INPUT_SYMBOL_SIZE; i++) {

        #pragma HLS pipeline II=1

        if(in[i].frequency != 0) {

            out[j].frequency = in[i].frequency;

            out[j].value = in[i].value;

            j++;
        }
    }
	
    *n = j;
}

void sort(

    /* input */ Symbol in[INPUT_SYMBOL_SIZE],

    /* input */ int num_symbols,

    /* output */ Symbol out[INPUT_SYMBOL_SIZE]) {

    Symbol previous_sorting[INPUT_SYMBOL_SIZE], sorting[INPUT_SYMBOL_SIZE];

    ap_uint<SYMBOL_BITS> digit_histogram[RADIX], digit_location[RADIX];

    #pragma HLS ARRAY_PARTITION variable=digit_location complete dim=1

    #pragma HLS ARRAY_PARTITION variable=digit_histogram complete dim=1

    Digit current_digit[INPUT_SYMBOL_SIZE];

    assert(num_symbols >= 0);

    assert(num_symbols <= INPUT_SYMBOL_SIZE);

copy_in_to_sorting:

    for(int j = 0; j < num_symbols; j++) {

        #pragma HLS PIPELINE II=1

        sorting[j] = in[j];
    }

radix_sort:

    for(int shift = 0; shift < 32; shift += BITS_PER_LOOP) {

    init_histogram:

        for(int i = 0; i < RADIX; i++) {

            #pragma HLS pipeline II=1

            digit_histogram[i] = 0;
        }

    compute_histogram:

        for(int j = 0; j < num_symbols; j++) {

            #pragma HLS PIPELINE II=1

            Digit digit = (sorting[j].frequency >> shift) & (RADIX - 1); // Extrract a digit

            current_digit[j] = digit;  // Store the current digit for each symbol

            digit_histogram[digit]++;

            previous_sorting[j] = sorting[j]; // Save the current sorted order of symbols
        }

        digit_location[0] = 0;

    find_digit_location:

        for(int i = 1; i < RADIX; i++)

            #pragma HLS PIPELINE II=1

            digit_location[i] = digit_location[i-1] + digit_histogram[i-1];

    re_sort:

        for(int j = 0; j < num_symbols; j++) {

            #pragma HLS PIPELINE II=1

            Digit digit = current_digit[j];

            sorting[digit_location[digit]] = previous_sorting[j]; // Move symbol to new sorted location

            out[digit_location[digit]] = previous_sorting[j]; // Also copy to output

            digit_location[digit]++; // Update digit_location
        }
    }
}

void compute_bit_length (

    /* input */ ap_uint<SYMBOL_BITS> parent[INPUT_SYMBOL_SIZE-1],

    /* input */ ap_uint<SYMBOL_BITS> left[INPUT_SYMBOL_SIZE-1],

    /* input */ ap_uint<SYMBOL_BITS> right[INPUT_SYMBOL_SIZE-1],

    /* input */ int num_symbols,

    /* output */ ap_uint<SYMBOL_BITS> length_histogram[TREE_DEPTH]) {

    assert(num_symbols > 0);

    assert(num_symbols <= INPUT_SYMBOL_SIZE);

    ap_uint<TREE_DEPTH_BITS> child_depth[INPUT_SYMBOL_SIZE-1];

    ap_uint<SYMBOL_BITS> internal_length_histogram[TREE_DEPTH];

 init_histogram:

    for(int i = 0; i < TREE_DEPTH; i++) {

        #pragma HLS pipeline II=1

        internal_length_histogram[i] = 0;
    }

    child_depth[num_symbols-2] = 1; // Depth of the root node is 1.

traverse_tree:

    for(int i = num_symbols-3; i >= 0; i--) {

        #pragma HLS pipeline II=3

        ap_uint<TREE_DEPTH_BITS> length = child_depth[parent[i]] + 1;

        child_depth[i] = length;

        if(left[i] != INTERNAL_NODE || right[i] != INTERNAL_NODE){

            int children;

            if(left[i] != INTERNAL_NODE && right[i] != INTERNAL_NODE) {

                // Both the children of the original node were symbols

                children = 2;
            } else {

                // One child of the original node was a symbol

                children = 1;
            }

            ap_uint<SYMBOL_BITS> count = internal_length_histogram[length];

            count += children;

            internal_length_histogram[length] = count;

            length_histogram[length] = count;
        }
    }
}

void truncate_tree(

    /* input */ ap_uint<SYMBOL_BITS> input_length_histogram[TREE_DEPTH],

    /* output */ ap_uint<SYMBOL_BITS> output_length_histogram1[TREE_DEPTH],

    /* output */ ap_uint<SYMBOL_BITS> output_length_histogram2[TREE_DEPTH]

) {

    // Copy into temporary storage to maintain dataflow properties

 copy_input:

    for(int i = 0; i < TREE_DEPTH; i++) {

        output_length_histogram1[i] = input_length_histogram[i];
    }

    ap_uint<SYMBOL_BITS> j = MAX_CODEWORD_LENGTH;

 move_nodes:

    for(int i = TREE_DEPTH - 1; i > MAX_CODEWORD_LENGTH; i--) {

        // Look to see if there is any nodes at lengths greater than target depth

    reorder:

        while(output_length_histogram1[i] != 0) {

            #pragma HLS LOOP_TRIPCOUNT min=3 max=3 avg=3

            if (j == MAX_CODEWORD_LENGTH) {

                // Find deepest leaf with codeword length < target depth

                do {

                    #pragma HLS LOOP_TRIPCOUNT min=1 max=1 avg=1

                    j--;

                } while(output_length_histogram1[j] == 0);

            }

            // Move leaf with depth i to depth j+1.

            output_length_histogram1[j] -= 1; // The node at level j is no longer a leaf.

            output_length_histogram1[j+1] += 2; // Two new leaf nodes are attached at level j+1.

            output_length_histogram1[i-1] += 1; // The leaf node at level i+1 gets attached here.

            output_length_histogram1[i] -= 2; // Two leaf nodes have been lost from level i.

            // now deepest leaf with codeword length < target length

            // is at level (j+1) unless j+1 == target length

            j++;
        }
    }

    // Copy the output to meet dataflow requirements and check the validity

    unsigned int limit = 1;

copy_output:

    for(int i = 0; i < TREE_DEPTH; i++) {

        output_length_histogram2[i] = output_length_histogram1[i];

        assert(output_length_histogram1[i] >= 0);

        assert(output_length_histogram1[i] <= limit);

        limit *= 2;
    }
}

void canonize_tree(

    /* input */ Symbol sorted[INPUT_SYMBOL_SIZE],

    /* input */ ap_uint<SYMBOL_BITS> num_symbols,

    /* input */ ap_uint<SYMBOL_BITS> codeword_length_histogram[TREE_DEPTH],

    /* output */ CodewordLength symbol_bits[INPUT_SYMBOL_SIZE] ) {

    assert(num_symbols <= INPUT_SYMBOL_SIZE);

init_bits:

    for(int i = 0; i < INPUT_SYMBOL_SIZE; i++) {

        symbol_bits[i] = 0;
    }

    ap_uint<SYMBOL_BITS> length = TREE_DEPTH;

    ap_uint<SYMBOL_BITS> count = 0;

    // Iterate across the symbols from lowest frequency to highest

    // Assign them largest bit length to smallest

process_symbols:

    for(int k = 0; k < num_symbols; k++) {

        if (count == 0) {

            //find the next non-zero bit length

            do {

                #pragma HLS LOOP_TRIPCOUNT min=1 avg=1 max=2

                length--;

                // n is the number of symbols with encoded length i

                count = codeword_length_histogram[length];
            }
            while (count == 0);
        }

        symbol_bits[sorted[k].value] = length; //assign symbol k to have length bits

        count--; //keep assigning i bits until we have counted off n symbols
    }
}
void create_codeword(

  /* input */ CodewordLength symbol_bits[INPUT_SYMBOL_SIZE],

  /* input */ ap_uint<SYMBOL_BITS> codeword_length_histogram[TREE_DEPTH],

  /* output */ PackedCodewordAndLength encoding[INPUT_SYMBOL_SIZE]

) {

    Codeword first_codeword[MAX_CODEWORD_LENGTH];

    // Computes the initial codeword value for a symbol with bit length i

    first_codeword[0] = 0;

first_codewords:

    for(int i = 1; i < MAX_CODEWORD_LENGTH; i++) {

        #pragma HLS PIPELINE II=1

        first_codeword[i] = (first_codeword[i-1] + codeword_length_histogram[i-1]) << 1;

        Codeword c = first_codeword[i];

        //        std::cout << c.to_string(2) << " with length " << i << "\n";
    }

assign_codewords:

    for (int i = 0; i < INPUT_SYMBOL_SIZE; ++i) {

        #pragma HLS PIPELINE II=5

        CodewordLength length = symbol_bits[i];

        //if symbol has 0 bits, it doesn't need to be encoded

    make_codeword:

        if(length != 0) {

            //          std::cout << first_codeword[length].to_string(2) << "\n";

            Codeword out_reversed = first_codeword[length];

            out_reversed.reverse();

            out_reversed = out_reversed >> (MAX_CODEWORD_LENGTH - length);

            // std::cout << out_reversed.to_string(2) << "\n";

            encoding[i] = (out_reversed << CODEWORD_LENGTH_BITS) + length;

            first_codeword[length]++;

        } else {

            encoding[i] = 0;
        }
    }
}

void huffman(

    /* input */ Symbol symbol_histogram[INPUT_SYMBOL_SIZE],

    /* output */ PackedCodewordAndLength encoding[INPUT_SYMBOL_SIZE],

    /* output */ int *num_nonzero_symbols) {
    #pragma HLS INTERFACE axis register both port=num_nonzero_symbols
    #pragma HLS INTERFACE axis register both port=encoding
    #pragma HLS INTERFACE axis register both port=symbol_histogram
    #pragma HLS INTERFACE ap_ctrl_none port=return

    Symbol filtered[INPUT_SYMBOL_SIZE];

    Symbol sorted[INPUT_SYMBOL_SIZE];

    Symbol sorted_copy1[INPUT_SYMBOL_SIZE];

    Symbol sorted_copy2[INPUT_SYMBOL_SIZE];

    ap_uint<SYMBOL_BITS> parent[INPUT_SYMBOL_SIZE-1];

    ap_uint<SYMBOL_BITS> left[INPUT_SYMBOL_SIZE-1];

    ap_uint<SYMBOL_BITS> right[INPUT_SYMBOL_SIZE-1];

    int n;

    filter(symbol_histogram, filtered, &n);

    sort(filtered, n, sorted);

    ap_uint<SYMBOL_BITS> length_histogram[TREE_DEPTH];

    ap_uint<SYMBOL_BITS> truncated_length_histogram1[TREE_DEPTH];

    ap_uint<SYMBOL_BITS> truncated_length_histogram2[TREE_DEPTH];

    CodewordLength symbol_bits[INPUT_SYMBOL_SIZE];

    int previous_frequency = -1;

copy_sorted:

    for(int i = 0; i < n; i++) {

        sorted_copy1[i].value = sorted[i].value;

        sorted_copy1[i].frequency = sorted[i].frequency;

        sorted_copy2[i].value = sorted[i].value;

        sorted_copy2[i].frequency = sorted[i].frequency;

         std::cout << sorted[i].value << " " << sorted[i].frequency << "\n";

        previous_frequency = sorted[i].frequency;
    }

    create_tree(sorted_copy1, n, parent, left, right);

    compute_bit_length(parent, left, right, n, length_histogram);

#ifndef __SYNTHESIS__

    // Check the result of computing the tree histogram

    int codewords_in_tree = 0;

merge_bit_length:

    for(int i = 0; i < TREE_DEPTH; i++) {

        #pragma HLS PIPELINE II=1

        if(length_histogram[i] > 0)

            std::cout << length_histogram[i] << " codewords with length " << i << "\n";

        codewords_in_tree += length_histogram[i];
    }

#endif

    truncate_tree(length_histogram, truncated_length_histogram1, truncated_length_histogram2);

    canonize_tree(sorted_copy2, n, truncated_length_histogram1, symbol_bits);

    create_codeword(symbol_bits, truncated_length_histogram2, encoding);

    *num_nonzero_symbols = n;
}
