#!/usr/bin/python3
# create_model.py
import numpy as np

import configparser
import sys

def isfloat(value):
	try:
		float(value)
		return True
	except ValueError:
		return False

def mean(data):
	"""Return the sample arithmetic mean of data."""
	n = len(data)
	if n < 1:
		raise ValueError('mean requires at least one data point')
	return sum(data)/float(n) # in Python 2 use sum(data)/float(n)


def _ss(data):
	"""Return sum of square deviations of sequence data."""
	c = mean(data)
	ss = sum((x-c)**2 for x in data)
	return ss


def stddev(data, ddof=0):
	"""Calculates the population standard deviation
	by default; specify ddof=1 to compute the sample
	standard deviation."""
	n = len(data)
	if n < 2:
		raise ValueError('variance requires at least two data points')
	ss = _ss(data)
	pvar = ss/(n-ddof)
	return pvar**0.5


def readfilesobj(filename,obj):
	with open(filename) as f:
		return [ [num for num in [float(s) for s in line.split(" ")[1:] if s.strip() and isfloat(s)]] for line in f if line.split(" ")[0] == obj+":"]

def readfiles(filename):
	with open(filename) as f:
		return [ [num for num in [float(s) for s in line.split(" ")[1:] if s.strip() and isfloat(s)]] for line in f]


config = configparser.ConfigParser()
if len(sys.argv) != 2:
	print("please feed the config file")
	exit
config.read(sys.argv[1])
maxCombUnitpool = int(config['DEFAULT']['maxCombUnitpool'])
maxCombUnitwatcher = int(config['DEFAULT']['maxCombUnitwatcher'])
unitDim = int(config['DEFAULT']['unitDim'])
pool = int(config['DEFAULT']['pool'])
watchers = [int(x) for x in config['DEFAULT']['watchers'].split(',')]
outputcategory = int(config['DEFAULT']['outputcategory'])
modelname = config['DEFAULT']['modelname']

nobj = 0
for x in watchers:
	nobj+=x
nwatcies = nobj
nobj+=pool

startpool = nwatcies
endpool = nobj
startwatcher = 0
endwatcher = nwatcies

#startpool = 0
#endpool = pool
#startwatcher = pool
#endwatcher = nobj


rawdatatrain = readfiles(config['DEFAULT']['traindata'])
invmassrec = [int(rawdatatrain[x][1]) for x in range(0,len(rawdatatrain)) if (x+1)%(nobj+1) == 0]
tausdata=readfilesobj(config['DEFAULT']['traindata'],"taus")
pooldata=[readfilesobj(config['DEFAULT']['traindata'],"pool"+str(i)) for i in range(0,pool)]
testweight = [rawdatatest[x][0] for x in range(0,len(rawdatatest)) if (x+1)%(nobj+1) == 0]

file = TFile("FCNCDr.root","update")
hist = (TH2D)file.Get("hist")
if(hist == None):
	hist = TH2D("hist","hist"100,0,6,100,0,6)

for i in range(0,len(pooldata[0])):
	tau1 = TLorentzVector()
	tau1.SetPtEtaPhiM(tausdata[i/2][0],tausdata[i/2][0],tausdata[i/2][0],tausdata[i/2][0])
	tau2.SetPtEtaPhiM(tausdata[i/2+1][0],tausdata[i/2+1][0],tausdata[i/2+1][0],tausdata[i/2+1][0])
	drFCNC = pooldata[invmassrec[i]][i].DeltaR(tau1+tau2)
	for j in range(0,pool):
		if(j == invmassrec[i]):
			continue
		hist.fill(drFCNC,pooldata[j][i].DeltaR(tau1+tau2),testweight[i])

file.cd()
hist.Write("hist",TObject::kWriteDelete)
print(invmassrec)
