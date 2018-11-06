from pynq import Overlay


__author__ = "sonnyhcl"

class CordicOverlay(Overlay):
	
    def __init__(self, bitfile="cordic.bit", **kwargs):
        super().__init__(bitfile, **kwargs)
        if self.is_loaded():
        	print("load ready")