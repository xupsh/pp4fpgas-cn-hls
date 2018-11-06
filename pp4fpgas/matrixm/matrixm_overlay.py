from pynq import Overlay


__author__ = "sonnyhcl"

class MatrixmOverlay(Overlay):
	
    def __init__(self, bitfile="matrixm.bit", **kwargs):
        super().__init__(bitfile, **kwargs)
        if self.is_loaded():
        	print("load ready")