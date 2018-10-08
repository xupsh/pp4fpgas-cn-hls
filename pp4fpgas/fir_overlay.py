from pynq import Overlay


__author__ = "sonnyhcl"

class FirOverlay(Overlay):
	
    def __init__(self, bitfile, **kwargs):
        super().__init__(bitfile, **kwargs)
        if self.is_loaded():
        	print("load ready")