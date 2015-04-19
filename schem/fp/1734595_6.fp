# author: Stefan Salewski
# email: mail@ssalewski.de
# dist-license: GPL
# use-license: unlimited

# DFN with center exposed thermal pad
Element[0x00000000 "DFN with center pad" "" "" 0 0 -8389 -13185 0 100 0x00000000]
(
	Pad[-3.700mm -2.50mm -2.750mm -2.50mm 0.6mm 0.6mm 0.6mm "1" "1" 0x00000100]
	Pad[-3.700mm -1.50mm -2.750mm -1.50mm 0.6mm 0.6mm 0.6mm "2" "2" 0x00000100]
	Pad[-3.700mm -0.50mm -2.750mm -0.50mm 0.6mm 0.6mm 0.6mm "3" "3" 0x00000100]
	Pad[-3.700mm  0.50mm -2.750mm  0.50mm 0.6mm 0.6mm 0.6mm "4" "4" 0x00000100]
	Pad[-3.700mm  1.50mm -2.750mm  1.50mm 0.6mm 0.6mm 0.6mm "5" "5" 0x00000100]
	Pad[-3.700mm  2.50mm -2.750mm  2.50mm 0.6mm 0.6mm 0.6mm "6" "6" 0x00000100]

	Pad[-1.000mm -3.70mm -0.400mm -3.70mm 1.2mm 1.2mm 1.2mm "7" "7" 0x00000100]
	Pad[-1.000mm  3.70mm -0.400mm  3.70mm 1.2mm 1.2mm 1.2mm "8" "8" 0x00000100]

	ElementLine[ 0.0mm -2.90mm  0.0mm  2.90mm 1000]

	ElementLine[-1.8mm  4.15mm -2.9mm  4.15mm 1000]
	ElementLine[-2.9mm  4.15mm -2.9mm  3.00mm 1000]

	ElementLine[-1.8mm -4.15mm -2.9mm -4.15mm 1000]
	ElementLine[-2.9mm -4.15mm -2.9mm -3.00mm 1000]

)
