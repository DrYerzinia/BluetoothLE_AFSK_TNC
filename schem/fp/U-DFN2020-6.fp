# author: Stefan Salewski
# email: mail@ssalewski.de
# dist-license: GPL
# use-license: unlimited

# DFN with center exposed thermal pad
Element[0x00000000 "DFN with center pad" "" "" 0 0 -8389 -13185 0 100 0x00000000]
(
	Pad[-0.965mm -0.65mm -0.885mm -0.65mm 0.37mm 0.37mm 0.37mm "1" "1" 0x00000100]
	Pad[-0.965mm  0.00mm -0.885mm  0.00mm 0.37mm 0.37mm 0.37mm "2" "2" 0x00000100]
	Pad[-0.965mm  0.65mm -0.885mm  0.65mm 0.37mm 0.37mm 0.37mm "3" "3" 0x00000100]
	Pad[ 0.965mm  0.65mm  0.885mm  0.65mm 0.37mm 0.37mm 0.37mm "4" "4" 0x00000100]
	Pad[ 0.965mm  0.00mm  0.885mm  0.00mm 0.37mm 0.37mm 0.37mm "5" "5" 0x00000100]
	Pad[ 0.965mm -0.65mm  0.885mm -0.65mm 0.37mm 0.37mm 0.37mm "6" "6" 0x00000100]

	Pad[-0.15mm -0.45mm 0.15mm -0.45mm 0.6mm 0.6mm 0.6mm "7" "7" 0x00000100]
	Pad[-0.15mm  0.45mm 0.15mm  0.45mm 0.6mm 0.6mm 0.6mm "8" "8" 0x00000100]

	ElementLine [-1mm -1mm  1mm -1mm 1000]
	ElementLine [ 1mm  1mm -1mm  1mm 1000]

