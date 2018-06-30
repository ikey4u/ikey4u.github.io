#! /usr/bin/python
#! -*- coding:utf-8 -*-
import idc
import idautils
import idaapi
import re

def decrypt(addr, initkey, key):
    cnt, savedaddr = 0, addr
    loopkey = initkey
    addr += 1
    while True:
        cnt += 1
        b = loopkey ^ key
        bb = idc.Byte(addr - 1)
        idc.PatchByte(addr - 1, b)
        print('[+] %s => %s' % (hex(bb), hex(idc.Byte(addr - 1))))
        addr += 1
        loopkey = idc.Byte(addr)
        if(not idc.Byte(addr - 1)):break
    print("[*] Decrypt and patch %d bytes from %s ." % (cnt, hex(savedaddr)))

def decrypt_tail():
    index, end = 0x27c, 0x420
    base = 0xAB9 & 0xFFFFFFFE
    key = 0x6674632a
    while True:
        curaddr = base + index
        word = idc.Word(curaddr)
        idc.PatchWord(curaddr, idc.Word(curaddr + 2))
        idc.PatchWord(curaddr + 2, word)
        idc.PatchDword(curaddr, idc.Dword(curaddr) ^ key)
        index += 4
        if(index >= end):break


def decrypt_final():

    # 1: 获取加密后的字节数组
    secret = []
    secret_base = 0xe54
    while True:
        b = idc.Byte(secret_base)
        if(not b):break
        secret.append(hex(b)[2:].zfill(2))
        secret_base += 1

    # 2: 从 list 中索引 index 处获得一个整数
    def getint_fromlist(index, lst):
        end = len(lst) - 1 if index + 3 > len(lst) - 1 else index + 3
        num = ""
        for i in range(end, index - 1, -1):
            hx = lst[i]
            num += hx
        return int(num,16)

    # 3: 在 list 索引 index 处放入一个整数 num
    def setint_tolist(index, lst, num):
        num = hex(num)[2:].zfill(8)
        numlst = re.findall(r".{1,2}", num)
        lsb = numlst[-1::-1]
        end = len(lst) - 1 if index + 3 > len(lst) - 1 else index + 3
        lst[index:end + 1] = lsb[0:end + 1 - index]


    # 4: 模拟加密(a)
    key = 0x6674632a
    square_key = key * key

    v = getint_fromlist(19, secret)
    setint_tolist(19, secret, (square_key >> 32) ^ v)
    vv = getint_fromlist(15, secret)
    setint_tolist(15, secret, vv ^ square_key)

    # 5: 模拟加密(b)
    for i in range(8):
        v = getint_fromlist(i, secret)
        num = getint_fromlist(i + 4, secret)
        setint_tolist(i, secret, v ^ square_key)
        setint_tolist(i + 4, secret, num ^ (square_key >> 32))

    # 6: 打印 flag
    flag = [chr(int(c,16)) for c in secret]
    print("[+] flag is %s" % (''.join(flag)))




'''
decrypt(0x2010,0xf0,0x93)
decrypt(0xcb4,0x73,0x10)
decrypt(0x2038,0x3e,0x16)
decrypt_tail()
decrypt_final()
'''
