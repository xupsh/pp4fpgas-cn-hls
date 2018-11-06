from pynq import Overlay


__author__ = "sonnyhcl"

class VsOverlay(Overlay):
	
    def __init__(self, bitfile="vs.bit", **kwargs):
        super().__init__(bitfile, **kwargs)
        if self.is_loaded():
        	print("load ready")