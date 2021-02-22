#include <iostream>

std::vector<TString> tthMLfakeNPlist = {
	//"fakeSF_tthML",
	//"fakeSF_origin",
	//"fakeSFNP_tthML_ptbin0_prongbin0",
	//"fakeSFNP_tthML_ptbin1_prongbin0",
	//"fakeSFNP_tthML_ptbin2_prongbin0",
	//"fakeSFNP_tthML_ptbin0_prongbin1",
	//"fakeSFNP_tthML_ptbin1_prongbin1",
	//"fakeSFNP_tthML_ptbin2_prongbin1",
	//"fakeSFNP_origin_0",
	//"fakeSFNP_origin_1",
	//"fakeSFNP_origin_2",
	//"fakeSFNP_origin_3",
	//"fakeSFNP_origin_4",
	//"fakeSFNP_origin_5",
	//"fakeSFNP_origin_6",
	//"fakeSFNP_origin_7",
  	//fitting stats. uncertainty, 24 parameters, reduce_run 5 to apply
	"fakeSFNP_1prong_ptbin0_b_fake", 
	"fakeSFNP_1prong_ptbin0_w_jet_fake_os",
	"fakeSFNP_1prong_ptbin0_w_jet_fake_ss",
	"fakeSFNP_1prong_ptbin0_other_fake",
	"fakeSFNP_3prong_ptbin0_b_fake",
	"fakeSFNP_3prong_ptbin0_w_jet_fake_os",
	"fakeSFNP_3prong_ptbin0_w_jet_fake_ss",
	"fakeSFNP_3prong_ptbin0_other_fake",
	"fakeSFNP_1prong_ptbin1_b_fake", 
	"fakeSFNP_1prong_ptbin1_w_jet_fake_os",
	"fakeSFNP_1prong_ptbin1_w_jet_fake_ss",
	"fakeSFNP_1prong_ptbin1_other_fake",
	"fakeSFNP_3prong_ptbin1_b_fake",
	"fakeSFNP_3prong_ptbin1_w_jet_fake_os",
	"fakeSFNP_3prong_ptbin1_w_jet_fake_ss",
	"fakeSFNP_3prong_ptbin1_other_fake",
	"fakeSFNP_1prong_ptbin2_b_fake", 
	"fakeSFNP_1prong_ptbin2_w_jet_fake_os",
	"fakeSFNP_1prong_ptbin2_w_jet_fake_ss",
	"fakeSFNP_1prong_ptbin2_other_fake",
	"fakeSFNP_3prong_ptbin2_b_fake",
	"fakeSFNP_3prong_ptbin2_w_jet_fake_os",
	"fakeSFNP_3prong_ptbin2_w_jet_fake_ss",
	"fakeSFNP_3prong_ptbin2_other_fake"
	//"fake_mismodelling" //mis-modelling in SS region, the data-MC difference is added to OS w-jet faking uncertainty, make_plots (2nd time) to apply.
};

std::vector<TString> xTFWfakeNPlist={
  "FFNP_1prong_ptbin0_etabin0", 
  "FFNP_1prong_ptbin0_etabin1",
  "FFNP_1prong_ptbin1_etabin0",
  "FFNP_1prong_ptbin1_etabin1",
  "FFNP_1prong_ptbin2_etabin0",
  "FFNP_1prong_ptbin2_etabin1",
  "FFNP_3prong_ptbin0_etabin0", 
  "FFNP_3prong_ptbin0_etabin1",
  "FFNP_3prong_ptbin1_etabin0",
  "FFNP_3prong_ptbin1_etabin1",
  "FFNP_3prong_ptbin2_etabin0",
  "FFNP_3prong_ptbin2_etabin1",
  "FFNP_samesign",
  "FFNP_sideband"
};

std::vector<TString> commonNPlist = { //common NP for both tthML and xTFW
	"PRW_up",
	"PRW_down",
	"jvt_up",
	"jvt_down",
	"tauRecon_TOTAL_up",
	"tauRecon_TOTAL_down",
	"tauEveto_TOTAL_up",
	"tauEveto_TOTAL_down",
	"tauEveto_EL_STAT_up",
	"tauEveto_EL_STAT_down",
	"tauEveto_EL_SYST_up",
	"tauEveto_EL_SYST_down",
	"MEDIUM_tauID_1P2025_up",
	"MEDIUM_tauID_1P2025_down",
	"MEDIUM_tauID_1P2530_up",
	"MEDIUM_tauID_1P2530_down",
	"MEDIUM_tauID_1P3040_up",
	"MEDIUM_tauID_1P3040_down",
	"MEDIUM_tauID_1PGE40_up",
	"MEDIUM_tauID_1PGE40_down",
	"MEDIUM_tauID_3P2025_up",
	"MEDIUM_tauID_3P2025_down",
	"MEDIUM_tauID_3P2530_up",
	"MEDIUM_tauID_3P2530_down",
	"MEDIUM_tauID_3P3040_up",
	"MEDIUM_tauID_3P3040_down",
	"MEDIUM_tauID_3PGE40_up",
	"MEDIUM_tauID_3PGE40_down",
	"MEDIUM_tauID_HIGHPT_up",
	"MEDIUM_tauID_HIGHPT_down",
	"MEDIUM_tauID_SYST_up",
	"MEDIUM_tauID_SYST_down",
//};
//std::vector<TString> btagNPlist = {
	"btag_B_0_down",
	"btag_B_0_up",
	"btag_B_10_down",
	"btag_B_10_up",
	"btag_B_11_down",
	"btag_B_11_up",
	"btag_B_12_down",
	"btag_B_12_up",
	"btag_B_13_down",
	"btag_B_13_up",
	"btag_B_14_down",
	"btag_B_14_up",
	"btag_B_15_down",
	"btag_B_15_up",
	"btag_B_16_down",
	"btag_B_16_up",
	"btag_B_17_down",
	"btag_B_17_up",
	"btag_B_18_down",
	"btag_B_18_up",
	"btag_B_19_down",
	"btag_B_19_up",
	"btag_B_1_down",
	"btag_B_1_up",
	"btag_B_20_down",
	"btag_B_20_up",
	"btag_B_21_down",
	"btag_B_21_up",
	"btag_B_22_down",
	"btag_B_22_up",
	"btag_B_23_down",
	"btag_B_23_up",
	"btag_B_24_down",
	"btag_B_24_up",
	"btag_B_25_down",
	"btag_B_25_up",
	"btag_B_26_down",
	"btag_B_26_up",
	"btag_B_27_down",
	"btag_B_27_up",
	"btag_B_28_down",
	"btag_B_28_up",
	"btag_B_29_down",
	"btag_B_29_up",
	"btag_B_2_down",
	"btag_B_2_up",
	"btag_B_30_down",
	"btag_B_30_up",
	"btag_B_31_down",
	"btag_B_31_up",
	"btag_B_32_down",
	"btag_B_32_up",
	"btag_B_33_down",
	"btag_B_33_up",
	"btag_B_34_down",
	"btag_B_34_up",
	"btag_B_35_down",
	"btag_B_35_up",
	"btag_B_36_down",
	"btag_B_36_up",
	"btag_B_37_down",
	"btag_B_37_up",
	"btag_B_38_down",
	"btag_B_38_up",
	"btag_B_39_down",
	"btag_B_39_up",
	"btag_B_3_down",
	"btag_B_3_up",
	"btag_B_40_down",
	"btag_B_40_up",
	"btag_B_41_down",
	"btag_B_41_up",
	"btag_B_42_down",
	"btag_B_42_up",
	"btag_B_43_down",
	"btag_B_43_up",
	"btag_B_44_down",
	"btag_B_44_up",
	"btag_B_4_down",
	"btag_B_4_up",
	"btag_B_5_down",
	"btag_B_5_up",
	"btag_B_6_down",
	"btag_B_6_up",
	"btag_B_7_down",
	"btag_B_7_up",
	"btag_B_8_down",
	"btag_B_8_up",
	"btag_B_9_down",
	"btag_B_9_up",
	"btag_C_0_down",
	"btag_C_0_up",
	"btag_C_10_down",
	"btag_C_10_up",
	"btag_C_11_down",
	"btag_C_11_up",
	"btag_C_12_down",
	"btag_C_12_up",
	"btag_C_13_down",
	"btag_C_13_up",
	"btag_C_14_down",
	"btag_C_14_up",
	"btag_C_15_down",
	"btag_C_15_up",
	"btag_C_16_down",
	"btag_C_16_up",
	"btag_C_17_down",
	"btag_C_17_up",
	"btag_C_18_down",
	"btag_C_18_up",
	"btag_C_19_down",
	"btag_C_19_up",
	"btag_C_1_down",
	"btag_C_1_up",
	"btag_C_2_down",
	"btag_C_2_up",
	"btag_C_3_down",
	"btag_C_3_up",
	"btag_C_4_down",
	"btag_C_4_up",
	"btag_C_5_down",
	"btag_C_5_up",
	"btag_C_6_down",
	"btag_C_6_up",
	"btag_C_7_down",
	"btag_C_7_up",
	"btag_C_8_down",
	"btag_C_8_up",
	"btag_C_9_down",
	"btag_C_9_up",
	"btag_Light_0_down",
	"btag_Light_0_up",
	"btag_Light_10_down",
	"btag_Light_10_up",
	"btag_Light_11_down",
	"btag_Light_11_up",
	"btag_Light_12_down",
	"btag_Light_12_up",
	"btag_Light_13_down",
	"btag_Light_13_up",
	"btag_Light_14_down",
	"btag_Light_14_up",
	"btag_Light_15_down",
	"btag_Light_15_up",
	"btag_Light_16_down",
	"btag_Light_16_up",
	"btag_Light_17_down",
	"btag_Light_17_up",
	"btag_Light_18_down",
	"btag_Light_18_up",
	"btag_Light_19_down",
	"btag_Light_19_up",
	"btag_Light_1_down",
	"btag_Light_1_up",
	"btag_Light_2_down",
	"btag_Light_2_up",
	"btag_Light_3_down",
	"btag_Light_3_up",
	"btag_Light_4_down",
	"btag_Light_4_up",
	"btag_Light_5_down",
	"btag_Light_5_up",
	"btag_Light_6_down",
	"btag_Light_6_up",
	"btag_Light_7_down",
	"btag_Light_7_up",
	"btag_Light_8_down",
	"btag_Light_8_up",
	"btag_Light_9_down",
	"btag_Light_9_up",
};

std::vector<TString> theoryNPlist = { // theory uncertainties, the recipe is changed, need to ask conveners.
	"muR=10,muF=20",
	"muR=10,muF=05",
	"muR=20,muF=10",
	"muR=05,muF=10",
	"muR=05,muF=05",
	"muR=20,muF=20",
	"muR=20,muF=05",
	"muR=05,muF=20",
	"PDFset=260001",
	"PDFset=260002",
	"PDFset=260003",
	"PDFset=260004",
	"PDFset=260005",
	"PDFset=260006",
	"PDFset=260007",
	"PDFset=260008",
	"PDFset=260009",
	"PDFset=260010",
	"PDFset=260011",
	"PDFset=260012",
	"PDFset=260013",
	"PDFset=260014",
	"PDFset=260015",
	"PDFset=260016",
	"PDFset=260017",
	"PDFset=260018",
	"PDFset=260019",
	"PDFset=260020",
	"PDFset=260021",
	"PDFset=260022",
	"PDFset=260023",
	"PDFset=260024",
	"PDFset=260025",
	"PDFset=260026",
	"PDFset=260027",
	"PDFset=260028",
	"PDFset=260029",
	"PDFset=260030",
	"PDFset=260031",
	"PDFset=260032",
	"PDFset=260033",
	"PDFset=260034",
	"PDFset=260035",
	"PDFset=260036",
	"PDFset=260037",
	"PDFset=260038",
	"PDFset=260039",
	"PDFset=260040",
	"PDFset=260041",
	"PDFset=260042",
	"PDFset=260043",
	"PDFset=260044",
	"PDFset=260045",
	"PDFset=260046",
	"PDFset=260047",
	"PDFset=260048",
	"PDFset=260049",
	"PDFset=260050",
	"PDFset=260051",
	"PDFset=260052",
	"PDFset=260053",
	"PDFset=260054",
	"PDFset=260055",
	"PDFset=260056",
	"PDFset=260057",
	"PDFset=260058",
	"PDFset=260059",
	"PDFset=260060",
	"PDFset=260061",
	"PDFset=260062",
	"PDFset=260063",
	"PDFset=260064",
	"PDFset=260065",
	"PDFset=260066",
	"PDFset=260067",
	"PDFset=260068",
	"PDFset=260069",
	"PDFset=260070",
	"PDFset=260071",
	"PDFset=260072",
	"PDFset=260073",
	"PDFset=260074",
	"PDFset=260075",
	"PDFset=260076",
	"PDFset=260077",
	"PDFset=260078",
	"PDFset=260079",
	"PDFset=260080",
	"PDFset=260081",
	"PDFset=260082",
	"PDFset=260083",
	"PDFset=260084",
	"PDFset=260085",
	"PDFset=260086",
	"PDFset=260087",
	"PDFset=260088",
	"PDFset=260089",
	"PDFset=260090",
	"PDFset=260091",
	"PDFset=260092",
	"PDFset=260093",
	"PDFset=260094",
	"PDFset=260095",
	"PDFset=260096",
	"PDFset=260097",
	"PDFset=260098",
	"PDFset=260099",
	"PDFset=260100",
	"ISR_up",
	"ISR_down",
	"FSR_up",
	"FSR_down"
};

std::vector<TString> xTFWNPlist = {
	"tauTrigger_STATDATA2018up",
	"tauTrigger_STATDATA2018down",
	"tauTrigger_STATMC2018up",
	"tauTrigger_STATMC2018down",
	"tauTrigger_SYST2018up",
	"tauTrigger_SYST2018down",
	"tauTrigger_SYSTMU2018up",
	"tauTrigger_SYSTMU2018down",
	"tauTrigger_STATDATA161718up",
	"tauTrigger_STATDATA161718down",
	"tauTrigger_STATMC161718up",
	"tauTrigger_STATMC161718down",
	"tauTrigger_SYST161718up",
	"tauTrigger_SYST161718down",
	"tauTrigger_SYSTMU161718up",
	"tauTrigger_SYSTMU161718down"
};
std::vector<TString> tthMLNPlist = {
	"El_ChargeMisID_STAT_up",
	"El_ChargeMisID_STAT_down",
	"El_ChargeMisID_SYST_up",
	"El_ChargeMisID_SYST_down",
	"El_Reco_up",
	"El_Reco_down",
	"El_ID_TightLH_up",
	"El_ID_TightLH_down",
	"El_Iso_FCLoose_up",
	"El_Iso_FCLoose_down",
	"Mu_TTVA_STAT_up",
	"Mu_TTVA_STAT_down",
	"Mu_TTVA_SYST_up",
	"Mu_TTVA_SYST_down",
	"Mu_ID_STAT_up",
	"Mu_ID_STAT_down",
	"Mu_ID_SYST_up",
	"Mu_ID_SYST_down",
	"Mu_ID_STAT_LOWPT_up",
	"Mu_ID_STAT_LOWPT_down",
	"Mu_ID_SYST_LOWPT_up",
	"Mu_ID_SYST_LOWPT_down",
	"Mu_Iso_SYST_up",
	"Mu_Iso_SYST_down",
	"Mu_Iso_STAT_up",
	"Mu_Iso_STAT_down",
	"eTrigger_up",
	"eTrigger_down",
	"muTrigger_Stat_up",
	"muTrigger_Stat_down",
	"muTrigger_Syst_up",
	"muTrigger_Syst_down",
};

std::vector<TString> tthMLtreeNPlist = {
	"MUON_ID_1down",
	"MUON_ID_1up",
	"MUON_MS_1down",
	"MUON_MS_1up",
	"MUON_SAGITTA_RESBIAS_1down",
	"MUON_SAGITTA_RESBIAS_1up",
	"MUON_SAGITTA_RHO_1down",
	"MUON_SAGITTA_RHO_1up",
	"MUON_SCALE_1down",
	"MUON_SCALE_1up",
	"EG_RESOLUTION_ALL_1down",
	"EG_RESOLUTION_ALL_1up",
	"EG_SCALE_AF2_1down",
	"EG_SCALE_AF2_1up",
	"EG_SCALE_ALL_1down",
	"EG_SCALE_ALL_1up",
};
std::vector<TString> xTFWtreeNPlist = {};
std::vector<TString> commontreeNPlist = {
	"JET_JER_DataVsMC_MC16_1up",
	"JET_JER_DataVsMC_MC16_1down",  
	"JET_PunchThrough_MC16_1up",
	"JET_PunchThrough_MC16_1down",
	"JET_TILECORR_Uncertainty_1down",
	"JET_TILECORR_Uncertainty_1up",
	"JET_BJES_Response_1down",
	"JET_BJES_Response_1up",
	"JET_EffectiveNP_Detector1_1down",
	"JET_EffectiveNP_Detector1_1up",
	"JET_EffectiveNP_Detector2_1down",
	"JET_EffectiveNP_Detector2_1up",
	"JET_EffectiveNP_Mixed1_1down",
	"JET_EffectiveNP_Mixed1_1up",
	"JET_EffectiveNP_Mixed2_1down",
	"JET_EffectiveNP_Mixed2_1up",
	"JET_EffectiveNP_Mixed3_1down",
	"JET_EffectiveNP_Mixed3_1up",
	"JET_EffectiveNP_Modelling1_1down",
	"JET_EffectiveNP_Modelling1_1up",
	"JET_EffectiveNP_Modelling2_1down",
	"JET_EffectiveNP_Modelling2_1up",
	"JET_EffectiveNP_Modelling3_1down",
	"JET_EffectiveNP_Modelling3_1up",
	"JET_EffectiveNP_Modelling4_1down",
	"JET_EffectiveNP_Modelling4_1up",
	"JET_EffectiveNP_Statistical1_1down",
	"JET_EffectiveNP_Statistical1_1up",
	"JET_EffectiveNP_Statistical2_1down",
	"JET_EffectiveNP_Statistical2_1up",
	"JET_EffectiveNP_Statistical3_1down",
	"JET_EffectiveNP_Statistical3_1up",
	"JET_EffectiveNP_Statistical4_1down",
	"JET_EffectiveNP_Statistical4_1up",
	"JET_EffectiveNP_Statistical5_1down",
	"JET_EffectiveNP_Statistical5_1up",
	"JET_EffectiveNP_Statistical6_1down",
	"JET_EffectiveNP_Statistical6_1up",
	"JET_EtaIntercalibration_Modelling_1down",
	"JET_EtaIntercalibration_Modelling_1up",
	"JET_EtaIntercalibration_NonClosure_2018data_1down",
	"JET_EtaIntercalibration_NonClosure_2018data_1up",
	"JET_EtaIntercalibration_NonClosure_highE_1down",
	"JET_EtaIntercalibration_NonClosure_highE_1up",
	"JET_EtaIntercalibration_NonClosure_negEta_1down",
	"JET_EtaIntercalibration_NonClosure_negEta_1up",
	"JET_EtaIntercalibration_NonClosure_posEta_1down",
	"JET_EtaIntercalibration_NonClosure_posEta_1up",
	"JET_EtaIntercalibration_TotalStat_1down",
	"JET_EtaIntercalibration_TotalStat_1up",
	"JET_Flavor_Composition_1down",
	"JET_Flavor_Composition_1up",
	"JET_Flavor_Response_1down",
	"JET_Flavor_Response_1up",
	"JET_JER_EffectiveNP_1_1down",
	"JET_JER_EffectiveNP_1_1up",
	"JET_JER_EffectiveNP_2_1down",
	"JET_JER_EffectiveNP_2_1up",
	"JET_JER_EffectiveNP_3_1down",
	"JET_JER_EffectiveNP_3_1up",
	"JET_JER_EffectiveNP_4_1down",
	"JET_JER_EffectiveNP_4_1up",
	"JET_JER_EffectiveNP_5_1down",
	"JET_JER_EffectiveNP_5_1up",
	"JET_JER_EffectiveNP_6_1down",
	"JET_JER_EffectiveNP_6_1up",
	"JET_JER_EffectiveNP_7restTerm_1down",
	"JET_JER_EffectiveNP_7restTerm_1up",
	"JET_Pileup_OffsetMu_1down",
	"JET_Pileup_OffsetMu_1up",
	"JET_Pileup_OffsetNPV_1down",
	"JET_Pileup_OffsetNPV_1up",
	"JET_Pileup_PtTerm_1down",
	"JET_Pileup_PtTerm_1up",
	"JET_Pileup_RhoTopology_1down",
	"JET_Pileup_RhoTopology_1up",
	"JET_PunchThrough_AFII_1down",
	"JET_PunchThrough_AFII_1up",
	"JET_RelativeNonClosure_AFII_1down",
	"JET_RelativeNonClosure_AFII_1up",
	"JET_SingleParticle_HighPt_1down",
	"JET_SingleParticle_HighPt_1up",
	"MET_SoftTrk_ResoPara",
	"MET_SoftTrk_ResoPerp",
	"MET_SoftTrk_Scale_1down",
	"MET_SoftTrk_Scale_1up",
	"TAUS_TRUEHADTAU_SME_TES_DETECTOR_1down",
	"TAUS_TRUEHADTAU_SME_TES_DETECTOR_1up",
	"TAUS_TRUEHADTAU_SME_TES_INSITUEXP_1down",
	"TAUS_TRUEHADTAU_SME_TES_INSITUEXP_1up",
	"TAUS_TRUEHADTAU_SME_TES_INSITUFIT_1down",
	"TAUS_TRUEHADTAU_SME_TES_INSITUFIT_1up",
	"TAUS_TRUEHADTAU_SME_TES_MODEL_CLOSURE_1down",
	"TAUS_TRUEHADTAU_SME_TES_MODEL_CLOSURE_1up",
	"TAUS_TRUEHADTAU_SME_TES_PHYSICSLIST_1down",
	"TAUS_TRUEHADTAU_SME_TES_PHYSICSLIST_1up",
};

std::vector<TString> sampleNPlist = {
	"ttbarsys_frag",
	"ttbarsys_hscatter",
};

std::vector<TString> xsecNPlist = {
	"ztautauXsec_up",
	"ztautauXsec_down",
	"ttbarXsec_up",
	"ttbarXsec_down",
};

std::vector<TString> tthMLmajorNPlist = {
	"tauEveto_TOTAL_up",
	"tauEveto_TOTAL_down",
	"tauEveto_E_TOTAL_up",
	"tauEveto_E_TOTAL_down",
	"tauID_TOTAL_up",
	"tauID_TOTAL_down",
	"tauID_HIGHPT_up",
	"tauID_HIGHPT_down",
	"tauRecon_TOTAL_up",
	"tauRecon_TOTAL_down",
	"tauRecon_HIGHPT_up",
	"tauRecon_HIGHPT_down",
};

std::vector<TString> tthMLmajortreeNPlist = {
	"TAUS_TRUEHADTAU_SME_TES_DETECTOR_1down",
	"TAUS_TRUEHADTAU_SME_TES_DETECTOR_1up",
	"TAUS_TRUEHADTAU_SME_TES_INSITU_1down",
	"TAUS_TRUEHADTAU_SME_TES_INSITU_1up",
	"TAUS_TRUEHADTAU_SME_TES_MODEL_1down",
	"TAUS_TRUEHADTAU_SME_TES_MODEL_1up"
};

std::vector<TString> xTFWmajorNPlist = {};


TString findNPname(TString &dirname, int iNP = 0, TString framework = "tthML"){

	int npidx = iNP;
	if(iNP == 0) {
		dirname = framework == "tthML"? "nominal" : "NOMINAL";
		return "NOMINAL";
	}else
		npidx--;
	std::vector<TString> *specNPlist = framework == "xTFW"?&xTFWNPlist:&tthMLNPlist;
	std::vector<TString> *treeNPlist = framework == "xTFW"?&xTFWtreeNPlist:&tthMLtreeNPlist;
	std::vector<TString> *fakeNPlist = framework == "xTFW"?&xTFWfakeNPlist:&tthMLfakeNPlist;
	std::vector<std::vector<TString>*> nlist = {fakeNPlist,&commonNPlist,specNPlist,&commontreeNPlist,treeNPlist,&theoryNPlist,&sampleNPlist};
	//std::vector<std::vector<TString>*> nlist = {treeNPlist,fakeNPlist,&commonNPlist,specNPlist,&theoryNPlist,&sampleNPlist};
	//except fakeNP, rerun from reduce 3 to update NPs.
	int totalNP = 0;
	for (int i = 0; i < nlist.size(); ++i)
	{
		if(npidx < nlist[i]->size()) {
			if(i == 3 || i == 4) dirname = nlist[i]->at(npidx);
			//if(i == 0) dirname = nlist[i]->at(npidx);
			else dirname = framework == "tthML"? "nominal" : "NOMINAL";
			return nlist[i]->at(npidx);
		}
		else npidx-=nlist[i]->size();
		totalNP += nlist[i]->size();
	}
	printf("NP %d not found, %d NPs in total\n", iNP, totalNP);
	return "";
}

//root -l
//.L weightsys_list.h
//printNPindex("tthML")
void printNPindex(TString framework = "tthML"){

	std::vector<TString> *specNPlist = framework == "xTFW"?&xTFWNPlist:&tthMLNPlist;
	std::vector<TString> *treeNPlist = framework == "xTFW"?&xTFWtreeNPlist:&tthMLtreeNPlist;
	std::vector<TString> *fakeNPlist = framework == "xTFW"?&xTFWfakeNPlist:&tthMLfakeNPlist;
	std::vector<std::vector<TString>*> nlist = {fakeNPlist,&commonNPlist,specNPlist,&commontreeNPlist,treeNPlist,&theoryNPlist,&sampleNPlist};
	int iNP = 1;
	std::ofstream file;
	file.open("NPlist.txt");
	for (auto ilist : nlist)
	{
		for( auto NP : *ilist){
			file << iNP << " " << NP << std::endl;
			iNP++;
		}
	}
	file.close();
}
