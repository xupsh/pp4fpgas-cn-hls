from pynq import Overlay


__author__ = "sonnyhcl"

class HistogramOverlay(Overlay):
	
    def __init__(self, bitfile="histogram.bit", **kwargs):
        super().__init__(bitfile, **kwargs)
        if self.is_loaded():
        	print("load ready")