v 20130925 2
T 23300 18300 9 10 1 0 0 0 1
AUDIO IN
T 23300 17300 9 10 1 0 0 0 2
AUDIO OUT

C 24900 18300 1 0 0 capacitor-1.sym
{
T 25100 19000 5 10 0 0 0 0 1
device=CAPACITOR
T 24900 18600 5 10 1 1 0 0 1
refdes=C60
T 25100 19200 5 10 0 0 0 0 1
symversion=0.1
T 25500 18400 5 10 1 1 180 6 1
footprint=0402
T 25500 18600 5 10 1 1 0 0 1
value=1uF
}
N 22000 18500 24900 18500 4
C 27500 18700 1 90 0 resistor-1.sym
{
T 27100 19000 5 10 0 0 90 0 1
device=RESISTOR
T 27600 19300 5 10 1 1 0 0 1
refdes=R60
T 27600 18900 5 10 1 1 0 0 1
footprint=0402
T 27600 19100 5 10 1 1 0 0 1
value=10k
}
C 27500 17400 1 90 0 resistor-1.sym
{
T 27100 17700 5 10 0 0 90 0 1
device=RESISTOR
T 27600 18000 5 10 1 1 0 0 1
refdes=R61
T 27600 17600 5 10 1 1 0 0 1
footprint=0402
T 27600 17800 5 10 1 1 0 0 1
value=10k
}
C 27300 16900 1 0 0 gnd-1.sym
C 19900 19300 1 180 0 connector4-2.sym
{
T 19200 19500 5 10 1 1 0 2 1
refdes=AUD
T 19600 17250 5 10 0 0 0 8 1
device=CONNECTOR_4
T 20000 17150 5 10 1 1 0 8 1
footprint=SJ_43515
}
C 24700 17500 1 0 0 capacitor-1.sym
{
T 24900 18200 5 10 0 0 0 0 1
device=CAPACITOR
T 24700 17800 5 10 1 1 0 0 1
refdes=C61
T 24900 18400 5 10 0 0 0 0 1
symversion=0.1
T 25300 17600 5 10 1 1 180 6 1
footprint=smt0603.ele
T 25300 17800 5 10 1 1 0 0 1
value=1uF
}
N 22000 17700 24700 17700 4
C 19300 20900 1 270 0 battery-1.sym
{
T 20200 20600 5 10 0 0 270 0 1
device=BATTERY
T 19700 20700 5 10 1 1 0 0 1
refdes=B1
T 20600 20600 5 10 0 0 270 0 1
symversion=0.1
T 19700 20400 5 10 1 1 0 0 1
footprint=BCAAPC
}
C 22900 18800 1 90 0 gnd-1.sym
N 20800 18900 22600 18900 4
T 23300 17900 9 10 1 0 0 0 1
PTT
N 20800 18100 23900 18100 4
{
T 24200 18000 5 10 1 1 0 0 1
netname=PPT
}
C 24300 17300 1 270 0 resistor-1.sym
{
T 24700 17000 5 10 0 0 270 0 1
device=RESISTOR
T 25000 16500 5 10 1 1 180 0 1
refdes=R62
T 25000 16900 5 10 1 1 180 0 1
footprint=0805
T 25000 16700 5 10 1 1 180 0 1
value=2.2k
}
N 24400 16200 24400 16400 4
{
T 24000 15700 5 10 1 1 0 0 1
netname=PPT_MIC
}
N 24400 17300 24400 17700 4
C 42200 20400 1 0 0 DSPIC33FJ64GP802.sym
{
T 46400 25200 5 10 1 1 0 0 1
device=DSPIC33FJ64GP802
T 52000 30100 5 10 1 1 0 6 1
footprint=QFN28_65
T 42600 30100 5 10 1 1 0 0 1
refdes=U1
}
C 32200 17200 1 0 0 AMS00X.sym
{
T 36800 21800 5 10 1 1 0 6 1
device=AMS00X
T 35100 19000 5 10 1 1 0 0 1
footprint=AMS00X
T 32600 21800 5 10 1 1 0 0 1
refdes=U2
}
C 52900 24800 1 0 0 capacitor-1.sym
{
T 53100 25500 5 10 0 0 0 0 1
device=CAPACITOR
T 53500 25100 5 10 1 1 0 0 1
refdes=C11
T 53100 25700 5 10 0 0 0 0 1
symversion=0.1
T 53200 24800 5 10 1 1 0 6 1
footprint=0603
T 53500 24800 5 10 1 1 0 0 1
value=4.7uF
}
N 52400 25000 52900 25000 4
C 52900 24500 1 90 0 gnd-1.sym
N 52400 24600 52600 24600 4
C 54400 24900 1 90 0 gnd-1.sym
N 53800 25000 54100 25000 4
C 47500 32600 1 270 0 capacitor-1.sym
{
T 48200 32400 5 10 0 0 270 0 1
device=CAPACITOR
T 48400 32400 5 10 0 0 270 0 1
symversion=0.1
T 48000 32500 5 10 1 1 0 0 1
refdes=C12
T 48000 32100 5 10 1 1 0 0 1
footprint=0402
T 48000 32300 5 10 1 1 0 0 1
value=100nF
}
C 47600 31200 1 0 0 gnd-1.sym
N 47700 31700 47700 31500 4
C 47500 32800 1 0 0 vdd-1.sym
N 47700 32600 47700 32800 4
C 47100 30600 1 0 0 vdd-1.sym
N 47300 30400 47300 30600 4
C 47800 30900 1 180 0 gnd-1.sym
N 47700 30600 47700 30400 4
C 41700 22400 1 270 0 capacitor-1.sym
{
T 42400 22200 5 10 0 0 270 0 1
device=CAPACITOR
T 42600 22200 5 10 0 0 270 0 1
symversion=0.1
T 41500 22200 5 10 1 1 0 6 1
refdes=C10
T 41500 21800 5 10 1 1 0 6 1
footprint=0402
T 41500 22000 5 10 1 1 0 6 1
value=100nF
}
C 41800 21000 1 0 0 gnd-1.sym
N 41900 21500 41900 21300 4
C 41700 22600 1 0 0 vdd-1.sym
N 41900 22400 41900 22600 4
C 41700 25100 1 270 0 gnd-1.sym
N 42200 25000 42000 25000 4
C 47100 20200 1 180 0 vdd-1.sym
N 46900 20400 46900 20200 4
C 37800 20800 1 270 0 capacitor-1.sym
{
T 38500 20600 5 10 0 0 270 0 1
device=CAPACITOR
T 38700 20600 5 10 0 0 270 0 1
symversion=0.1
T 38300 20600 5 10 1 1 0 0 1
refdes=C20
T 38300 20200 5 10 1 1 0 0 1
footprint=0603
T 38300 20400 5 10 1 1 0 0 1
value=4.7uF
}
C 37900 19400 1 0 0 gnd-1.sym
N 38000 19900 38000 19700 4
C 37800 21000 1 0 0 vdd-1.sym
N 38000 20800 38000 21000 4
C 37800 18700 1 270 0 capacitor-1.sym
{
T 38500 18500 5 10 0 0 270 0 1
device=CAPACITOR
T 38700 18500 5 10 0 0 270 0 1
symversion=0.1
T 38300 18400 5 10 1 1 0 0 1
refdes=C21
T 38300 18000 5 10 1 1 0 0 1
footprint=0402
T 38300 18200 5 10 1 1 0 0 1
value=10nF
}
C 37900 17300 1 0 0 gnd-1.sym
N 38000 17800 38000 17600 4
C 37800 18900 1 0 0 vdd-1.sym
N 38000 18700 38000 18900 4
C 37100 20000 1 0 0 vdd-1.sym
N 37200 19900 37300 19900 4
N 37300 19900 37300 20000 4
C 37600 19300 1 90 0 gnd-1.sym
N 37200 19400 37300 19400 4
C 37600 19000 1 90 0 gnd-1.sym
N 37200 19100 37300 19100 4
C 37600 18700 1 90 0 gnd-1.sym
N 37200 18800 37300 18800 4
C 37600 18400 1 90 0 gnd-1.sym
N 37200 18500 37300 18500 4
C 37600 18100 1 90 0 gnd-1.sym
N 37200 18200 37300 18200 4
C 37600 17800 1 90 0 gnd-1.sym
N 37200 17900 37300 17900 4
C 37600 17500 1 90 0 gnd-1.sym
N 37200 17600 37300 17600 4
C 37600 17200 1 90 0 gnd-1.sym
N 37200 17300 37300 17300 4
C 31600 20900 1 90 0 busripper-2.sym
{
T 31200 20900 5 8 0 0 90 0 1
device=none
}
N 31600 20900 32200 20900 4
{
T 31300 20800 5 10 1 1 0 6 1
netname=TX
}
C 32000 20000 1 90 0 busripper-2.sym
{
T 31600 20000 5 8 0 0 90 0 1
device=none
}
N 32000 20000 32200 20000 4
{
T 31700 19900 5 10 1 1 0 6 1
netname=RX
}
C 32000 21000 1 90 0 resistor-1.sym
{
T 31600 21300 5 10 0 0 90 0 1
device=RESISTOR
T 31100 21600 5 10 1 1 0 0 1
refdes=R20
T 31100 21200 5 10 1 1 0 0 1
footprint=0402
T 31100 21400 5 10 1 1 0 0 1
value=10k
}
C 31700 22000 1 0 0 vdd-1.sym
N 31900 21900 31900 22000 4
N 31900 21000 31900 20900 4
C 29600 20700 1 270 0 vdd-1.sym
N 29600 20500 29500 20500 4
C 29900 20800 1 90 0 gnd-1.sym
N 29600 20900 29500 20900 4
C 46900 30800 1 0 0 busripper-2.sym
{
T 46900 31200 5 8 0 0 0 0 1
device=none
}
N 46900 30800 46900 30400 4
{
T 47000 31100 5 10 1 1 90 0 1
netname=MCLR
}
C 29600 18900 1 270 0 busripper-2.sym
{
T 30000 18900 5 8 0 0 270 0 1
device=none
}
N 29600 18900 29500 18900 4
{
T 29900 18800 5 10 1 1 0 0 1
netname=MCLR
}
C 52600 26600 1 270 0 busripper-2.sym
{
T 53000 26600 5 8 0 0 270 0 1
device=none
}
N 52600 26600 52400 26600 4
{
T 52900 26500 5 10 1 1 0 0 1
netname=TX
}
C 52600 25800 1 270 0 busripper-2.sym
{
T 53000 25800 5 8 0 0 270 0 1
device=none
}
N 52600 25800 52400 25800 4
{
T 52900 25900 5 10 1 1 180 6 1
netname=RX
}
C 40300 24900 1 0 0 busripper-2.sym
{
T 40300 25300 5 8 0 0 0 0 1
device=none
}
N 40300 24900 40300 24700 4
{
T 40500 25200 5 10 1 1 0 6 1
netname=PPT
}
C 49200 19400 1 0 0 busripper-2.sym
{
T 49200 19800 5 8 0 0 0 0 1
device=none
}
N 49200 19400 49200 19200 4
{
T 48800 19700 5 10 1 1 0 0 1
netname=PPT_MIC
}
C 24400 16200 1 180 0 busripper-2.sym
{
T 24400 15800 5 8 0 0 180 0 1
device=none
}
C 23900 18100 1 270 0 busripper-2.sym
{
T 24300 18100 5 8 0 0 270 0 1
device=none
}
N 25800 17700 25600 17700 4
{
T 26100 17600 5 10 1 1 0 0 1
netname=AUD_OUT
}
C 25800 17700 1 270 0 busripper-2.sym
{
T 26200 17700 5 8 0 0 270 0 1
device=none
}
C 27200 19800 1 0 0 vdd-1.sym
N 27400 17400 27400 17200 4
N 25800 18500 27400 18500 4
N 27400 18300 27400 18700 4
N 27400 19800 27400 19600 4
C 27600 18500 1 270 0 busripper-2.sym
{
T 28000 18500 5 8 0 0 270 0 1
device=none
}
N 27400 18500 27600 18500 4
{
T 27900 18400 5 10 1 1 0 0 1
netname=AUD_IN
}
C 48500 30600 1 0 0 busripper-2.sym
{
T 48500 31000 5 8 0 0 0 0 1
device=none
}
N 48500 30400 48500 30600 4
{
T 48600 30900 5 10 1 1 90 0 1
netname=AUD_OUT
}
C 48100 30600 1 0 0 busripper-2.sym
{
T 48100 31000 5 8 0 0 0 0 1
device=none
}
N 48100 30400 48100 30600 4
{
T 48200 30900 5 10 1 1 90 0 1
netname=AUD_IN
}
C 48600 18200 1 0 0 NPN.sym
{
T 49500 18700 5 10 0 0 0 0 1
device=NPN_TRANSISTOR
T 49500 18800 5 10 1 1 0 0 1
refdes=Q3
T 49500 18600 5 10 1 1 0 0 1
footprint=SOT23
}
N 47500 18700 47300 18700 4
N 47300 18700 47300 20400 4
C 49100 17700 1 0 0 gnd-1.sym
N 49200 18000 49200 18200 4
C 40900 23700 1 0 1 NPN.sym
{
T 40000 24200 5 10 0 0 0 6 1
device=NPN_TRANSISTOR
T 40000 24300 5 10 1 1 0 6 1
refdes=Q2
T 40000 24100 5 10 1 1 0 6 1
footprint=SOT23
}
N 42200 24200 42000 24200 4
C 40200 23200 1 0 0 gnd-1.sym
N 40300 23500 40300 23700 4
C 46500 30800 1 90 0 resistor-1.sym
{
T 46100 31100 5 10 0 0 90 0 1
device=RESISTOR
T 45800 31500 5 10 1 1 0 0 1
refdes=R10
T 45800 31100 5 10 1 1 0 0 1
footprint=0402
T 45800 31300 5 10 1 1 0 0 1
value=10k
}
N 46900 30600 46400 30600 4
N 46400 30600 46400 30800 4
C 46200 31900 1 0 0 vdd-1.sym
N 46400 31700 46400 31900 4
C 47500 18600 1 0 0 resistor-1.sym
{
T 47800 19000 5 10 0 0 0 0 1
device=RESISTOR
T 47500 18900 5 10 1 1 0 0 1
refdes=R11
T 47500 18400 5 10 1 1 0 0 1
footprint=0402
}
N 48600 18700 48400 18700 4
C 41100 24100 1 0 0 resistor-1.sym
{
T 41400 24500 5 10 0 0 0 0 1
device=RESISTOR
T 41100 24400 5 10 1 1 0 0 1
refdes=R12
T 41100 23900 5 10 1 1 0 0 1
footprint=0402
}
N 40900 24200 41100 24200 4
N 20100 18900 19900 18900 4
N 21300 17700 19900 17700 4
N 20100 18100 19900 18100 4
N 21300 18500 19900 18500 4
C 20100 18500 1 0 0 FERRITE_BEAD.sym
{
T 19900 19000 5 10 1 1 0 0 1
refdes=FB1
T 20800 19000 5 10 1 1 0 0 1
footprint=0603
}
C 21300 18100 1 0 0 FERRITE_BEAD.sym
{
T 21100 18600 5 10 1 1 0 0 1
refdes=FB2
T 22000 18600 5 10 1 1 0 0 1
footprint=0603
}
C 21300 17300 1 0 0 FERRITE_BEAD.sym
{
T 21100 17800 5 10 1 1 0 0 1
refdes=FB4
T 21900 17800 5 10 1 1 0 0 1
footprint=0603
}
C 20100 17700 1 0 0 FERRITE_BEAD.sym
{
T 19900 18200 5 10 1 1 0 0 1
refdes=FB3
T 20800 18200 5 10 1 1 0 0 1
footprint=0603
}
C 53700 24400 1 180 0 led-1.sym
{
T 52900 23800 5 10 0 0 180 0 1
device=LED
T 53000 23500 5 10 1 1 0 0 1
refdes=LED11
T 52900 23600 5 10 0 0 180 0 1
symversion=0.1
T 53000 23300 5 10 1 1 0 0 1
footprint=0603
}
C 52800 22600 1 0 0 led-1.sym
{
T 53600 23200 5 10 0 0 0 0 1
device=LED
T 53000 22400 5 10 1 1 0 0 1
refdes=LED10
T 53600 23400 5 10 0 0 0 0 1
symversion=0.1
T 53000 22200 5 10 1 1 0 0 1
footprint=0603
}
C 55000 22900 1 180 0 resistor-1.sym
{
T 54700 22500 5 10 0 0 180 0 1
device=RESISTOR
T 54200 22900 5 10 1 1 0 6 1
refdes=R13
T 54900 22700 5 10 1 1 180 6 1
footprint=0603
T 54800 22900 5 10 1 1 0 0 1
value=220
}
C 54100 24100 1 0 0 resistor-1.sym
{
T 54400 24500 5 10 0 0 0 0 1
device=RESISTOR
T 54200 24300 5 10 1 1 0 6 1
refdes=R14
T 54900 24100 5 10 1 1 180 6 1
footprint=0603
T 54800 24300 5 10 1 1 0 0 1
value=220
}
N 52800 22800 52600 22800 4
N 52600 22800 52600 24200 4
N 52400 24200 52800 24200 4
N 53700 24200 54100 24200 4
N 53700 22800 54100 22800 4
C 55500 22700 1 90 0 gnd-1.sym
N 55000 22800 55200 22800 4
C 55200 24400 1 0 0 vdd-1.sym
N 55000 24200 55400 24200 4
N 55400 24200 55400 24400 4
C 37000 27100 1 180 0 DMP3030SN.sym
{
T 36400 26600 5 10 0 0 180 0 1
device=PMOS_TRANSISTOR
T 36300 26500 5 10 1 1 180 0 1
refdes=Q80
T 36300 26700 5 10 1 1 180 0 1
device=DMP3030SN
T 36300 26900 5 10 1 1 180 0 1
footprint=SOT23
}
C 37200 26800 1 0 0 resistor-1.sym
{
T 37500 27200 5 10 0 0 0 0 1
device=RESISTOR
T 37300 27000 5 10 1 1 0 6 1
refdes=R83
T 37400 27100 5 10 1 1 0 0 1
footprint=0402
T 37900 27000 5 10 1 1 0 0 1
value=330k
}
N 37000 26900 37200 26900 4
C 36600 25200 1 90 0 resistor-1.sym
{
T 36200 25500 5 10 0 0 90 0 1
device=RESISTOR
T 36300 25800 5 10 1 1 0 6 1
refdes=R80
T 36300 25400 5 10 1 1 0 6 1
footprint=0402
T 36300 25600 5 10 1 1 0 6 1
value=330k
}
C 36600 23900 1 90 0 resistor-1.sym
{
T 36200 24200 5 10 0 0 90 0 1
device=RESISTOR
T 36300 24500 5 10 1 1 0 6 1
refdes=R81
T 36300 24100 5 10 1 1 180 2 1
footprint=0402
T 36300 24300 5 10 1 1 0 6 1
value=330k
}
N 36500 26100 36500 26300 4
N 36500 24800 36500 25200 4
C 36400 23400 1 0 0 gnd-1.sym
N 36500 23900 36500 23700 4
N 36500 27100 36500 27300 4
{
T 36600 27600 5 10 1 1 90 0 1
netname=VBAT
}
C 36500 27300 1 0 1 busripper-2.sym
{
T 36500 27700 5 8 0 0 180 2 1
device=none
}
C 37200 25700 1 90 0 resistor-1.sym
{
T 36800 26000 5 10 0 0 90 0 1
device=RESISTOR
T 37300 26200 5 10 1 1 0 0 1
refdes=R82
T 37300 25800 5 10 1 1 180 8 1
footprint=0402
T 37300 26000 5 10 1 1 0 0 1
value=330k
}
C 37000 25200 1 0 0 gnd-1.sym
N 37100 25700 37100 25500 4
N 37100 26600 37100 26900 4
N 38100 26900 38300 26900 4
{
T 38800 26300 5 10 1 1 90 0 1
netname=EN_BAT_MEAS
}
C 38300 26900 1 270 0 busripper-2.sym
{
T 38700 26900 5 8 0 0 270 0 1
device=none
}
C 36000 25000 1 90 0 busripper-2.sym
{
T 35600 25000 5 8 0 0 90 0 1
device=none
}
N 36000 25000 36500 25000 4
{
T 35700 24900 5 10 1 1 0 6 1
netname=BAT_MEAS
}
C 52600 26200 1 270 0 busripper-2.sym
{
T 53000 26200 5 8 0 0 270 0 1
device=none
}
N 52600 26200 52400 26200 4
{
T 52900 26300 5 10 1 1 180 6 1
netname=BAT_MEAS
}
N 48500 20200 48700 20200 4
{
T 49000 20100 5 10 1 1 0 0 1
netname=EN_BAT_MEAS
}
C 48700 20200 1 270 0 busripper-2.sym
{
T 49100 20200 5 8 0 0 270 0 1
device=none
}
N 48500 20200 48500 20400 4
C 29500 18500 1 0 1 connector6-2.sym
{
T 28800 21400 5 10 1 1 180 8 1
refdes=PROG
T 29200 21350 5 10 0 0 180 2 1
device=CONNECTOR_6
T 28800 18350 5 10 1 1 0 2 1
footprint=1734595_6
}
C 29600 19300 1 270 0 busripper-2.sym
{
T 30000 19300 5 8 0 0 270 0 1
device=none
}
N 29600 19300 29500 19300 4
{
T 29900 19200 5 10 1 1 0 0 1
netname=VBAT
}
C 29600 20100 1 270 0 busripper-2.sym
{
T 30000 20100 5 8 0 0 270 0 1
device=none
}
N 29600 20100 29500 20100 4
{
T 29900 20000 5 10 1 1 0 0 1
netname=DAT
}
C 29600 19700 1 270 0 busripper-2.sym
{
T 30000 19700 5 8 0 0 270 0 1
device=none
}
N 29600 19700 29500 19700 4
{
T 29900 19600 5 10 1 1 0 0 1
netname=CLK
}
C 42100 26600 1 90 1 busripper-2.sym
{
T 41700 26600 5 8 0 0 270 2 1
device=none
}
N 42100 26600 42200 26600 4
{
T 41800 26500 5 10 1 1 0 6 1
netname=DAT
}
C 42100 26200 1 90 1 busripper-2.sym
{
T 41700 26200 5 8 0 0 270 2 1
device=none
}
N 42100 26200 42200 26200 4
{
T 41800 26100 5 10 1 1 0 6 1
netname=CLK
}
C 22200 23800 1 0 0 MCP7383.sym
{
T 22700 23800 5 10 1 1 0 0 1
footprint=SOT25
T 22700 25300 5 10 1 1 0 0 1
device=MCP7383
T 23900 25300 5 10 1 1 0 0 1
refdes=U3
}
C 21400 22900 1 0 1 gnd-1.sym
N 23600 19600 23300 19600 4
N 26100 24600 24600 24600 4
C 25500 24100 1 0 1 gnd-1.sym
N 19400 25000 20300 25000 4
N 24600 25000 25000 25000 4
N 26100 24600 26100 25000 4
C 21500 23300 1 90 0 capacitor-1.sym
{
T 20800 23500 5 10 0 0 90 0 1
device=CAPACITOR
T 20600 23500 5 10 0 0 90 0 1
symversion=0.1
T 20900 23900 5 10 1 1 0 0 1
refdes=C30
T 21400 23600 5 10 1 1 180 6 1
footprint=0603
T 21400 23900 5 10 1 1 0 0 1
value=4.7uF
}
N 21300 23200 21300 23300 4
N 19400 25000 19400 25200 4
{
T 19100 25500 5 10 1 1 0 0 1
netname=VUSB
}
C 22200 23200 1 90 0 resistor-1.sym
{
T 21800 23500 5 10 0 0 90 0 1
device=RESISTOR
T 22300 23600 5 10 1 1 0 0 1
refdes=R32
T 22300 23200 5 10 1 1 0 0 1
footprint=0402
T 22300 23400 5 10 1 1 0 0 1
value=2.2k
}
N 22100 24100 22100 24200 4
N 22100 24200 22200 24200 4
N 22100 23200 22100 23100 4
C 25900 25200 1 180 0 capacitor-1.sym
{
T 25700 24500 5 10 0 0 180 0 1
device=CAPACITOR
T 25700 24300 5 10 0 0 180 0 1
symversion=0.1
T 24900 25100 5 10 1 1 0 0 1
refdes=C31
T 25600 24900 5 10 1 1 180 6 1
footprint=0603
T 25600 25100 5 10 1 1 0 0 1
value=4.7uF
}
N 24800 25000 24800 25200 4
{
T 24500 25500 5 10 1 1 0 0 1
netname=VBAT
}
N 25900 25000 26100 25000 4
N 25400 24400 25400 24600 4
N 24600 24200 24800 24200 4
C 24500 19200 1 0 0 connector5-2.sym
{
T 24800 21650 5 10 0 0 0 0 1
device=CONNECTOR_5
T 25200 21700 5 10 1 1 0 6 1
refdes=USB
T 25450 20500 5 10 1 1 90 6 1
footprint=USB_MICRO_F
}
C 24800 25200 1 0 0 busripper-2.sym
{
T 24800 25600 5 8 0 0 0 0 1
device=none
}
C 19400 25200 1 0 0 busripper-2.sym
{
T 19400 25600 5 8 0 0 0 0 1
device=none
}
C 24300 20800 1 0 1 FERRITE_BEAD.sym
{
T 24500 21300 5 10 1 1 0 6 1
refdes=FB6
T 23600 21300 5 10 1 1 0 6 1
footprint=0603
}
C 24300 19200 1 0 1 FERRITE_BEAD.sym
{
T 24500 19700 5 10 1 1 0 6 1
refdes=FB5
T 23600 19700 5 10 1 1 0 6 1
footprint=0603
}
N 24300 19600 24500 19600 4
N 24500 21200 24300 21200 4
N 21200 25000 22200 25000 4
N 33900 30400 34100 30400 4
{
T 34400 30500 5 10 1 1 180 6 1
netname=VBAT
}
C 34100 30400 1 270 0 busripper-2.sym
{
T 34500 30400 5 8 0 0 270 0 1
device=none
}
C 23000 19700 1 270 0 gnd-1.sym
N 23600 21200 23300 21200 4
{
T 23000 21100 5 10 1 1 0 6 1
netname=VUSB
}
C 23300 21200 1 90 1 busripper-2.sym
{
T 22900 21200 5 8 0 0 270 2 1
device=none
}
N 19500 20900 19500 21100 4
{
T 19200 21400 5 10 1 1 0 0 1
netname=VBAT
}
C 19500 21100 1 0 0 busripper-2.sym
{
T 19500 21500 5 8 0 0 0 0 1
device=none
}
C 19600 19700 1 0 1 gnd-1.sym
N 19500 20000 19500 20200 4
N 21300 25000 21300 25700 4
N 21300 25700 21100 25700 4
N 20100 25000 20100 25700 4
N 20100 25700 20300 25700 4
N 21600 26500 21700 26500 4
{
T 22000 26400 5 10 1 1 0 0 1
netname=LICH
}
C 21700 26500 1 270 0 busripper-2.sym
{
T 22100 26500 5 8 0 0 270 0 1
device=none
}
B 18900 22400 7800 4900 3 0 0 0 -1 -1 0 -1 -1 -1 -1 -1
B 30300 28800 8600 4600 3 0 0 0 -1 -1 0 -1 -1 -1 -1 -1
B 18900 15500 11700 6500 3 0 0 0 -1 -1 0 -1 -1 -1 -1 -1
C 21200 24800 1 0 1 diode-3.sym
{
T 20750 25350 5 10 0 0 0 6 1
device=DIODE
T 20450 25250 5 10 1 1 0 0 1
refdes=D30
T 20500 24900 5 10 1 1 180 0 1
footprint=0805
T 20400 24600 5 10 1 1 180 6 1
value=500mA
}
C 22200 22800 1 0 1 gnd-1.sym
N 21300 24200 21300 25000 4
C 19900 25200 1 90 0 resistor-1.sym
{
T 19500 25500 5 10 0 0 90 0 1
device=RESISTOR
T 19900 26100 5 10 1 1 0 0 1
refdes=R33
T 19900 25900 5 10 1 1 0 0 1
footprint=0402
}
N 19800 25200 19800 25000 4
N 20500 26300 19800 26300 4
N 19800 26300 19800 26100 4
C 20700 26400 1 0 0 resistor-1.sym
{
T 21000 26800 5 10 0 0 0 0 1
device=RESISTOR
T 20500 26600 5 10 1 1 0 0 1
refdes=R34
T 21000 26700 5 10 1 1 0 0 1
footprint=0402
}
N 20700 26500 20500 26500 4
N 20500 26500 20500 26200 4
C 29200 32300 1 270 0 switch-spdt-1.sym
{
T 30000 31900 5 10 0 0 270 0 1
device=SPDT
T 29700 31200 5 10 0 1 0 0 1
footprint=SPDT1825232
T 29200 32200 5 10 1 1 90 6 1
refdes=S1
T 29000 32200 5 10 1 1 90 6 1
device=1825232-1
}
C 24100 29600 1 0 0 AS1337.sym
{
T 24500 31700 5 10 1 1 0 0 1
refdes=U5
T 26100 29900 5 10 1 1 180 0 1
device=AS1337
T 26100 31700 5 10 1 1 0 6 1
footprint=DFN8_65
}
C 25400 29100 1 0 1 gnd-1.sym
N 25300 29400 25300 29600 4
N 24100 31400 23900 31400 4
N 23900 31400 23900 32100 4
C 23600 30100 1 270 1 gnd-1.sym
N 23900 30200 24100 30200 4
C 22500 30100 1 0 1 gnd-1.sym
N 22400 30400 22400 30800 4
N 24100 30600 22400 30600 4
C 22600 30800 1 90 0 capacitor-1.sym
{
T 21900 31000 5 10 0 0 90 0 1
device=CAPACITOR
T 21700 31000 5 10 0 0 90 0 1
symversion=0.1
T 22300 31400 5 10 1 1 0 6 1
refdes=C50
T 22500 31500 5 10 1 1 0 0 1
footprint=0805W
}
N 22400 31700 22400 32100 4
N 20200 32100 25800 32100 4
C 23000 30900 1 0 0 inductor-1.sym
{
T 23200 31400 5 10 0 0 0 0 1
device=INDUCTOR
T 23200 31600 5 10 0 0 0 0 1
symversion=0.1
T 22800 31200 5 10 1 1 0 0 1
refdes=L50
T 23300 31200 5 10 1 1 0 0 1
footprint=1008
}
N 23900 31000 24100 31000 4
C 28600 29800 1 90 0 capacitor-1.sym
{
T 27900 30000 5 10 0 0 90 0 1
device=CAPACITOR
T 27700 30000 5 10 0 0 90 0 1
symversion=0.1
T 28300 30400 5 10 1 1 0 6 1
refdes=C51
T 28500 30400 5 10 1 1 0 0 1
footprint=0603
}
C 28500 29300 1 0 1 gnd-1.sym
N 28400 29600 28400 29800 4
C 25800 32000 1 0 0 resistor-1.sym
{
T 26100 32400 5 10 0 0 0 0 1
device=RESISTOR
T 25600 32300 5 10 1 1 0 0 1
refdes=R50
T 26100 32300 5 10 1 1 0 0 1
footprint=0402
}
C 27100 32000 1 0 0 resistor-1.sym
{
T 27400 32400 5 10 0 0 0 0 1
device=RESISTOR
T 26900 32300 5 10 1 1 0 0 1
refdes=R51
T 27400 32300 5 10 1 1 0 0 1
footprint=0402
}
C 28500 32200 1 90 1 gnd-1.sym
N 28200 32100 28000 32100 4
N 26700 32100 27100 32100 4
N 26500 31400 26900 31400 4
N 26900 31400 26900 32100 4
N 26500 30200 26700 30200 4
C 20700 30400 1 180 0 DMP3030SN.sym
{
T 20100 29900 5 10 0 0 180 0 1
device=PMOS_TRANSISTOR
T 20000 29800 5 10 1 1 180 0 1
refdes=Q51
T 20000 30000 5 10 1 1 180 0 1
device=DMP3030SN
T 20000 30200 5 10 1 1 180 0 1
footprint=SOT23
}
N 26500 31000 29200 31000 4
N 29400 32300 29400 32400 4
{
T 29100 32700 5 10 1 1 0 0 1
netname=VBAT
}
C 20900 29700 1 180 1 resistor-1.sym
{
T 21200 29300 5 10 0 0 180 6 1
device=RESISTOR
T 21400 29900 5 10 1 1 180 6 1
refdes=R54
T 20900 29900 5 10 1 1 180 6 1
footprint=0402
}
N 20800 29600 20800 30200 4
N 26700 31000 26700 30800 4
N 26700 30800 22800 30800 4
N 22800 30800 22800 31000 4
N 22800 31000 23000 31000 4
N 20700 30200 20900 30200 4
N 20200 30400 20200 32100 4
N 20800 29600 20900 29600 4
C 26700 30100 1 0 0 resistor-1.sym
{
T 27000 30500 5 10 0 0 0 0 1
device=RESISTOR
T 26500 30300 5 10 1 1 0 0 1
refdes=R58
T 27000 29900 5 10 1 1 0 0 1
footprint=0402
T 27400 30300 5 10 1 1 0 0 1
value=1M
}
N 27800 30200 27800 31000 4
C 26700 33100 1 180 0 capacitor-1.sym
{
T 26500 32400 5 10 0 0 180 0 1
device=CAPACITOR
T 26500 32200 5 10 0 0 180 0 1
symversion=0.1
T 26100 32700 5 10 1 1 0 6 1
refdes=C52
T 25700 33000 5 10 1 1 0 0 1
footprint=0402
T 26400 33000 5 10 1 1 0 0 1
value=100pF
}
N 26900 32100 26900 32900 4
N 26900 32900 26700 32900 4
N 25800 32900 25500 32900 4
N 25500 32900 25500 32100 4
C 29400 32400 1 0 1 busripper-2.sym
{
T 29400 32800 5 8 0 0 180 2 1
device=none
}
C 20400 29600 1 180 0 vdd-1.sym
N 27800 30200 27600 30200 4
N 21200 29100 21000 29100 4
{
T 20700 29000 5 10 1 1 0 6 1
netname=VUSB
}
C 21000 29100 1 90 1 busripper-2.sym
{
T 20600 29100 5 8 0 0 270 2 1
device=none
}
N 22100 29100 22200 29100 4
N 21800 29600 22200 29600 4
N 22200 29100 22200 29600 4
B 18900 27700 11100 5700 3 0 0 0 -1 -1 0 -1 -1 -1 -1 -1
C 22100 28900 1 0 1 diode-3.sym
{
T 21650 29450 5 10 0 0 0 6 1
device=DIODE
T 22250 28750 5 10 1 1 0 6 1
refdes=D50
T 20700 28800 5 10 1 1 0 0 1
footprint=0402
}
N 29200 31400 29200 31000 4
N 28400 30700 28400 31000 4
C 20900 30100 1 0 0 resistor-1.sym
{
T 21200 30500 5 10 0 0 0 0 1
device=RESISTOR
T 20900 30400 5 10 1 1 0 0 1
refdes=R52
T 21400 30400 5 10 1 1 0 0 1
footprint=0402
}
C 22200 30300 1 90 1 gnd-1.sym
N 21900 30200 21800 30200 4
N 33900 31200 35000 31200 4
N 35000 29600 35000 32800 4
N 31500 29600 35000 29600 4
N 32800 29600 32800 29800 4
N 31700 30400 31500 30400 4
N 31500 30400 31500 29600 4
N 32800 32000 32800 32200 4
N 32800 32200 35000 32200 4
N 33900 30800 34100 30800 4
N 34100 30800 34100 32400 4
N 34100 32400 31300 32400 4
N 31300 30900 31300 32800 4
N 31300 31200 31700 31200 4
C 31400 30000 1 90 0 resistor-1.sym
{
T 31000 30300 5 10 0 0 90 0 1
device=RESISTOR
T 30700 30500 5 10 1 1 0 0 1
refdes=R41
T 30700 30300 5 10 1 1 0 0 1
footprint=0402
}
C 31200 29500 1 0 0 gnd-1.sym
N 31300 29800 31300 30000 4
N 31200 32800 32500 32800 4
{
T 30900 32700 5 10 1 1 0 6 1
netname=VUSB
}
N 33400 32800 35000 32800 4
C 33400 32600 1 0 1 diode-3.sym
{
T 32950 33150 5 10 0 0 0 6 1
device=DIODE
T 32750 32750 5 10 1 1 180 0 1
refdes=D40
T 33200 32600 5 10 1 1 0 0 1
footprint=0402
}
N 36100 31200 35900 31200 4
C 35000 31300 1 180 1 resistor-1.sym
{
T 35300 30900 5 10 0 0 180 6 1
device=RESISTOR
T 35800 31300 5 10 1 1 0 0 1
refdes=R40
T 35600 31400 5 10 1 1 0 6 1
footprint=0402
}
N 36100 30600 35000 30600 4
C 20300 26200 1 270 0 NTJD4152P.sym
{
T 21200 25800 5 10 1 1 0 0 1
device=NTJD4152P
T 21200 26000 5 10 1 1 0 0 1
refdes=Q1
}
C 31200 32800 1 90 0 busripper-2.sym
{
T 30800 32800 5 8 0 0 90 0 1
device=none
}
C 31700 29800 1 0 0 DS31546.sym
{
T 32100 31700 5 10 1 1 0 0 1
refdes=U41
T 32900 31700 5 10 1 1 0 0 1
device=DS31546
T 32900 30000 5 10 1 1 0 0 1
footprint=U-DFN2020-6
}
T 18900 27400 9 10 1 0 0 0 1
LI-Ion Charge
T 30300 33500 9 10 1 0 0 0 2
USB regulator with battery bypass for
Li-Ion only version
T 35400 32000 9 10 1 0 0 0 2
Prevent volage flowing into VUSB
when usb voltage is disconnected
T 23000 25900 9 10 1 0 0 0 5
Diode prevents revese voltage from VDD
when not charging.  FET enables battery
chemistry charge selection.  In Li-Ion only
FET is not installed and vice versa for diode
in NiMH NiCD Alkaline Li-Ion version
T 18900 22100 9 10 1 0 0 0 1
Connectors
T 19000 33500 9 10 1 0 0 0 2
Buck-Boost regulator for
Alkaline NiMH NiCD compat
T 21500 32400 9 10 1 0 0 0 2
For proper operation output capacitor must
be as close as possible to VOUT and PGND
B 34600 23200 4300 5200 3 0 0 0 -1 -1 0 -1 -1 -1 -1 -1
T 34600 28500 9 10 1 0 0 0 1
Battery Measurement Circuit
B 30900 16900 8000 5700 3 0 0 0 -1 -1 0 -1 -1 -1 -1 -1
T 30900 22700 9 10 1 0 0 0 1
BLE Transceiver
B 39200 16900 16500 16500 3 0 0 0 -1 -1 0 -1 -1 -1 -1 -1
T 39200 33500 9 10 1 0 0 0 1
Processor
N 28900 25800 30300 25800 4
N 29300 26800 29500 26800 4
{
T 29800 26700 5 10 1 1 0 0 1
netname=NICH
}
C 29500 26800 1 270 0 busripper-2.sym
{
T 29900 26800 5 8 0 0 270 0 1
device=none
}
N 28100 25800 27900 25800 4
{
T 27600 25700 5 10 1 1 0 6 1
netname=VUSB
}
C 27900 25800 1 90 0 busripper-2.sym
{
T 27500 25800 5 8 0 0 90 0 1
device=none
}
B 27000 23000 7000 4300 3 0 0 0 -1 -1 0 -1 -1 -1 -1 -1
C 29300 26900 1 180 0 resistor-1.sym
{
T 29000 26500 5 10 0 0 180 0 1
device=RESISTOR
T 28500 26900 5 10 1 1 0 6 1
refdes=R72
T 28700 27000 5 10 1 1 0 0 1
footprint=0402
}
C 28200 26900 1 180 0 resistor-1.sym
{
T 27900 26500 5 10 0 0 180 0 1
device=RESISTOR
T 27400 26900 5 10 1 1 0 6 1
refdes=R71
T 27600 27000 5 10 1 1 0 0 1
footprint=0402
}
N 28300 26300 28300 26800 4
N 28200 26800 28400 26800 4
N 27300 26800 27200 26800 4
N 27200 26000 27200 26800 4
N 27200 26000 28000 26000 4
N 28000 26000 28000 25800 4
C 28100 26300 1 270 0 NTJD4152P.sym
{
T 28100 26300 5 10 0 0 270 0 1
slot=2
T 28500 26400 5 10 1 1 0 2 1
device=NTJD4152P
T 28500 26500 5 10 1 1 180 8 1
refdes=Q1
}
C 30300 24600 1 0 0 TC1071.sym
{
T 30700 26100 5 10 1 1 0 0 1
refdes=U7
T 30700 24700 5 10 1 1 180 6 1
device=TC1071
T 32000 26100 5 10 1 1 0 6 1
footprint=SOT25
}
C 33100 24800 1 90 0 resistor-1.sym
{
T 32700 25100 5 10 0 0 90 0 1
device=RESISTOR
T 33300 25300 5 10 1 1 0 0 1
refdes=R73
T 33300 25100 5 10 1 1 0 0 1
footprint=0402
}
N 32400 25800 33100 25800 4
{
T 33400 25700 5 10 1 1 0 0 1
netname=VBAT
}
N 33000 25800 33000 25700 4
C 33100 23700 1 90 0 resistor-1.sym
{
T 32700 24000 5 10 0 0 90 0 1
device=RESISTOR
T 33300 24200 5 10 1 1 0 0 1
refdes=R74
T 33300 24000 5 10 1 1 0 0 1
footprint=0402
}
N 33000 24600 33000 24800 4
N 33000 24700 32600 24700 4
N 32600 24700 32600 25000 4
N 32600 25000 32400 25000 4
C 32900 23300 1 0 0 gnd-1.sym
N 33000 23600 33000 23700 4
C 33100 25800 1 270 0 busripper-2.sym
{
T 33500 25800 5 8 0 0 270 0 1
device=none
}
C 33200 25900 1 90 0 capacitor-1.sym
{
T 32500 26100 5 10 0 0 90 0 1
device=CAPACITOR
T 32300 26100 5 10 0 0 90 0 1
symversion=0.1
T 32600 26500 5 10 1 1 0 0 1
refdes=C71
T 33100 26200 5 10 1 1 180 6 1
footprint=0402
T 33100 26500 5 10 1 1 0 0 1
value=1uF
}
N 33000 25800 33000 25900 4
C 33100 27200 1 180 0 gnd-1.sym
N 33000 26900 33000 26800 4
C 29900 25500 1 270 0 gnd-1.sym
N 30200 25400 30300 25400 4
C 29200 24700 1 90 0 capacitor-1.sym
{
T 28500 24900 5 10 0 0 90 0 1
device=CAPACITOR
T 28300 24900 5 10 0 0 90 0 1
symversion=0.1
T 28600 25300 5 10 1 1 0 0 1
refdes=C70
T 29100 25000 5 10 1 1 180 6 1
footprint=0402
T 29100 25300 5 10 1 1 0 0 1
value=1uF
}
N 29000 25600 29000 25800 4
C 28900 24300 1 0 0 gnd-1.sym
N 29000 24600 29000 24700 4
N 30300 25000 29800 25000 4
N 29800 25000 29800 25800 4
T 27000 27400 9 10 1 0 0 0 1
NiMH NiCD Charge
C 25000 23800 1 270 0 busripper-2.sym
{
T 25400 23800 5 8 0 0 270 0 1
device=none
}
N 25000 23800 24800 23800 4
{
T 25300 23700 5 10 1 1 0 0 1
netname=LI_CHRG_STAT
}
N 24800 23800 24800 24200 4
C 52600 25400 1 270 0 busripper-2.sym
{
T 53000 25400 5 8 0 0 270 0 1
device=none
}
N 52600 25400 52400 25400 4
{
T 52900 25500 5 10 1 1 180 6 1
netname=LI_CHRG_STAT
}
C 37800 30100 1 0 1 AAT3221.sym
{
T 37200 31500 5 10 1 1 0 0 1
refdes=U4
T 37400 30300 5 10 1 1 0 8 1
device=AAT3221
T 36400 31500 5 10 1 1 0 0 1
footprint=SOT25
}
C 35600 31000 1 270 0 gnd-1.sym
N 35900 30900 36100 30900 4
C 38000 30400 1 270 1 vdd-1.sym
N 37800 30600 38000 30600 4
C 38100 29600 1 90 0 capacitor-1.sym
{
T 37400 29800 5 10 0 0 90 0 1
device=CAPACITOR
T 37200 29800 5 10 0 0 90 0 1
symversion=0.1
T 37500 30200 5 10 1 1 0 0 1
refdes=C41
T 38000 29900 5 10 1 1 180 6 1
footprint=0402
T 38000 30200 5 10 1 1 0 0 1
value=1uF
}
C 36200 29600 1 90 0 capacitor-1.sym
{
T 35500 29800 5 10 0 0 90 0 1
device=CAPACITOR
T 35300 29800 5 10 0 0 90 0 1
symversion=0.1
T 35600 30200 5 10 1 1 0 0 1
refdes=C40
T 36100 29900 5 10 1 1 180 6 1
footprint=0402
T 36100 30200 5 10 1 1 0 0 1
value=1uF
}
N 36000 30500 36000 30600 4
N 37900 30500 37900 30600 4
C 35900 29200 1 0 0 gnd-1.sym
N 36000 29500 36000 29600 4
C 37800 29200 1 0 0 gnd-1.sym
N 37900 29500 37900 29600 4
N 42200 25400 42100 25400 4
{
T 41800 25300 5 10 1 1 0 6 1
netname=LICH
}
C 42100 25400 1 90 1 busripper-2.sym
{
T 41700 25400 5 8 0 0 270 2 1
device=none
}
N 42200 25800 42100 25800 4
{
T 41800 25700 5 10 1 1 0 6 1
netname=NICH
}
C 42100 25800 1 90 1 busripper-2.sym
{
T 41700 25800 5 8 0 0 270 2 1
device=none
}
