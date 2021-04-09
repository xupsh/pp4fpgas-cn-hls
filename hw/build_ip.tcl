# Rebuild HLS IP from source
set current_dir [pwd]
cd ip

# get list of IP from folder names
set ip {sort cordic fir dft matrixm histogram sum vs spmv fft huffman phase_detector OFDM mono_fm}

# Check and build each IP
foreach item $ip {
   if {[catch { glob -directory ${item}/solution1/impl/ip/ *.zip} zip_file]} {

# Build IP only if a packaged IP does not exist
      puts "Building $item IP"
      exec vivado_hls -f $item/script.tcl
   } else {

# Skip IP when a packaged IP exists in ip directory
      puts "Skipping building $item"
   }
   unset zip_file
}

cd $current_dir
puts "HLS IP builds complete"
