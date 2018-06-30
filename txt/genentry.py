#! /usr/bin/env python3
#! -*- coding:utf-8 -*-
import os
import glob
import json
entrypath = "entry.json"
blacktxt = []
txtfiles = [t for t in glob.glob("*.txt") if t not in blacktxt]
lentry = list()
record = set()
if(not os.path.exists(entrypath)):
    with open(entrypath,'w') as _:
        json.dump(lentry,_)
else:
    with open(entrypath,'r') as _:
        lentry = json.load(_)

if(len(lentry) > 0):
    record = set(lentry[-1])
    del lentry[-1]

for txtfile in txtfiles:
    with open(txtfile,'r') as f:
        line = f.readline().strip()
        # The first line begin with "@title" is scanned
        if("@title" not in line):
            continue
        # txt file is not included
        if(txtfile in record):
            continue
        title = line.replace("@title ","").strip()
        src = txtfile
        date = f.readline().replace("@date ","").strip()
        dtmp = {"title":title,"src":src,"date":date}
        lentry.append(dtmp)
        record.add(src)

sorted_lentry = sorted(lentry,key = lambda k:k['date'],reverse = True)
sorted_lentry.append(list(record))

with open(entrypath,'w') as _:
    json.dump(sorted_lentry,_)

