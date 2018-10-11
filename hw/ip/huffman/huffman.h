
#include "ap_int.h"


// input number of symbols

const static int INPUT_SYMBOL_SIZE = 256;

// upper bound on codeword length during tree construction

const static int TREE_DEPTH = 64;

// maximum codeword tree length after rebalancing

const static int MAX_CODEWORD_LENGTH = 27;

// Should be log2(INPUT_SYMBOL_SIZE)

const static int SYMBOL_BITS = 10;

// Should be log2(TREE_DEPTH)

const static int TREE_DEPTH_BITS = 6;

// number of bits needed to record MAX_CODEWORD_LENGTH value

// Should be log2(MAX_CODEWORD_LENGTH)

const static int CODEWORD_LENGTH_BITS = 5;

// A marker for internal nodes

const static ap_uint<SYMBOL_BITS> INTERNAL_NODE = -1;


typedef ap_uint<MAX_CODEWORD_LENGTH> Codeword;

typedef ap_uint<MAX_CODEWORD_LENGTH + CODEWORD_LENGTH_BITS> PackedCodewordAndLength;

typedef ap_uint<CODEWORD_LENGTH_BITS> CodewordLength;

typedef ap_uint<32> Frequency;


struct Symbol {

	 ap_uint<SYMBOL_BITS> value;

	 ap_uint<32> frequency;

};


const unsigned int RADIX = 16;

const unsigned int BITS_PER_LOOP = 4; // should be log2(RADIX)

typedef ap_uint<BITS_PER_LOOP> Digit;

