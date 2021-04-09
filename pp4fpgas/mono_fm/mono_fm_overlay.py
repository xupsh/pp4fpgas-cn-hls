import os
from pynq import Overlay

__author__ = "sonnyhcl"

REAL_PATH = os.path.dirname(os.path.realpath(__file__))

class CordicOverlay(Overlay):
    bitfile_name = ""

    def __init__(self, bitfile="", **kwargs):
        bitfile_abs = os.path.abspath(bitfile)
        bitfile_overlay_abs = os.path.join(REAL_PATH, bitfile)
        bitfile_default = os.path.join(REAL_PATH, "mono_fm.bit")

        if os.path.isfile(bitfile):
            self.bitfile_name = bitfile_abs
        elif os.path.isfile(bitfile_overlay_abs):
            self.bitfile_name = bitfile_overlay_abs
        else:
            self.bitfile_name = bitfile_default

        super().__init__(self.bitfile_name, **kwargs)

        if self.is_loaded():
                print(self.bitfile_name, "load ready")
