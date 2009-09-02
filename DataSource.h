
#ifndef DATASOURCE_H
#define DATASOURCE_H

#include "TString.h"
#include "TColor.h"
#include <iostream>

typedef UInt_t sources_t;

enum {
        H_WW      ,
        H_TTBAR   ,
        H_DYMM    ,
        H_DYEE    ,
        H_DYTT    ,
        H_WJETS   ,
        H_TW      ,
        H_ZZ      ,
        H_WZ,
	H_WENU,
	H_EM30_80,
	H_BC30_80,
	H_QCD30,
        H_QCD80,
	H_WJET_ALP,
	H_ZEEJET_ALP,
        H_ZMMJET_ALP,
        H_ZTTJET_ALP,
	H_MU15_SINGLE,

};

const static sources_t sources_all =
 (1ll << H_WW)          |
 (1ll << H_TTBAR)       |
 (1ll << H_DYMM)        |
 (1ll << H_DYEE)        |
 (1ll << H_DYTT)        |
 (1ll << H_WJETS)       |
 (1ll << H_TW)          |
 (1ll << H_ZZ)          |
 (1ll << H_WZ);

const static sources_t sources_dy =
 (1ll << H_DYMM)        |
 (1ll << H_DYEE);

const static sources_t sources_peaking =
 (1ll << H_DYMM)        |
 (1ll << H_DYEE)        |
 (1ll << H_ZZ)          |
 (1ll << H_WZ);

const static sources_t sources_nonpeaking =
 (1ll << H_WW)          |
 (1ll << H_TTBAR)       |
 (1ll << H_DYTT)        |
 (1ll << H_WJETS)       |
 (1ll << H_TW);

class DataSource {

        public:
		DataSource() {}
                DataSource(TString name, sources_t source, Color_t color = 0) {
                        sourceName_ = name;
                        source_ = source;
			color_ = color;
                }
		DataSource::DataSource(const DataSource &rhs) {
			sourceName_ = rhs.sourceName_;
			source_ = rhs.source_;
			color_ = rhs.color_;
		}
                ~DataSource() {}

                TString         getName()       { return sourceName_; }
                sources_t       getSource()     { return source_; }
		sources_t 	getBit()	{ return 1ll << source_; }
		Color_t		getColor()	{ return color_; }
        private:
                TString         sourceName_;
                sources_t       source_;
		Color_t		color_;

};

DataSource fH_WW();
DataSource fH_TTBAR();
DataSource fH_DYMM();
DataSource fH_DYEE();
DataSource fH_DYTT();
DataSource fH_WJETS();
DataSource fH_TW();
DataSource fH_ZZ();
DataSource fH_WZ();

DataSource fH_WENU();
DataSource fH_EM30_80();
DataSource fH_BC30_80();

DataSource fH_QCD30();
DataSource fH_QCD80();
DataSource fH_WJET_ALP();
DataSource fH_ZEEJET_ALP();
DataSource fH_ZMMJET_ALP();
DataSource fH_ZTTJET_ALP();

DataSource fH_MU15_SINGLE();

#endif
