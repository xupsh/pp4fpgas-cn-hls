from pynq import Overlay


__author__ = "sonnyhcl"

class SortOverlay(Overlay):
	
    def __init__(self, bitfile="sort.bit", **kwargs):
        super().__init__(bitfile, **kwargs)
        if self.is_loaded():
        	print("load ready")