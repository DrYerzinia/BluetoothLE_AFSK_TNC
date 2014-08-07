
.PHONY: build

build: create-dirs all

all: gerb/TNC_Li_Ion_Gerb.zip

create-dirs:
	mkdir -p gerb

gerb/TNC_Li_Ion_Gerb.zip:
	pcb -x gerber --gerberfile gerb/TNC_Li_Ion TNC_Li_Ion.pcb
	mv gerb/TNC_Li_Ion.top.gbr			gerb/TNC_Li_Ion.GTL
	mv gerb/TNC_Li_Ion.bottom.gbr		gerb/TNC_Li_Ion.GBL
	mv gerb/TNC_Li_Ion.bottommask.gbr	gerb/TNC_Li_Ion.GBS
	mv gerb/TNC_Li_Ion.topmask.gbr		gerb/TNC_Li_Ion.GTS
	mv gerb/TNC_Li_Ion.topsilk.gbr		gerb/TNC_Li_Ion.GTO
	mv gerb/TNC_Li_Ion.bottomsilk.gbr	gerb/TNC_Li_Ion.GBO
	mv gerb/TNC_Li_Ion.outline.gbr		gerb/TNC_Li_Ion.GKO
	mv gerb/TNC_Li_Ion.plated-drill.cnc	gerb/TNC_Li_Ion.XLN
	zip gerb/TNC_Li_Ion_Gerb.zip gerb/TNC_Li_Ion.GTL gerb/TNC_Li_Ion.GBL gerb/TNC_Li_Ion.GBS gerb/TNC_Li_Ion.GTS gerb/TNC_Li_Ion.GTO gerb/TNC_Li_Ion.GBO gerb/TNC_Li_Ion.GKO gerb/TNC_Li_Ion.XLN
	rm gerb/TNC_Li_Ion.*

clean:
	rm -rf gerb
