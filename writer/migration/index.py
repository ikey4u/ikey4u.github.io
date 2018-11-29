#! /usr/bin/env python3
#! -*- coding:utf-8 -*-

import re
import json

with open("./index.html", "r") as index:
    line = index.readline()
    jsonidx = list()
    while line:
        mat = re.findall(r"<a href=\"http://www.ahageek.com/blog/(.+?)\" target=\"_blank\">(.+?)</a>(.+?)<br/><br/>\s*", line)
        if len(mat) > 0:
            #  mat: [('linux-terminator-settings/', 'linux terminator settings', ' 2015.08.22')]
            mat = mat[0]
            tmp = dict()
            tmp["author"] = "bugnofree"
            tmp["link"] = mat[0].strip()
            tmp["date"] = mat[2].strip()
            tmp["title"] = mat[1].strip()
            jsonidx.append(tmp)
        line = index.readline()

    with open("index.json", "w") as _:
        json.dump(jsonidx, _)
