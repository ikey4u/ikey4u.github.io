#! /usr/bin/env python3
#! -*- coding:utf-8 -*-

r0 = 0x66
#Python>for addr in range(0x405320,0x405340): print hex(idc.Byte(addr)) + ',',
#0x89, 0xc1, 0xec, 0x50, 0x97, 0x3a, 0x57, 0x59, 0xe4, 0xe6, 0xe4, 0x42, 0xcb, 0xd9, 0x8, 0x22, 0xae, 0x9d, 0x7c, 0x7, 0x80, 0x8f, 0x1b, 0x45, 0x4, 0xe8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
another_secret =[0x89, 0xc1, 0xec, 0x50, 0x97, 0x3a, 0x57, 0x59, 0xe4, 0xe6, 0xe4, 0x42, 0xcb, 0xd9, 0x8, 0x22, 0xae, 0x9d, 0x7c, 0x7, 0x80, 0x8f, 0x1b, 0x45, 0x4, 0xe8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0]
right_input_rc4d = []
for i in range(0x1A):
    for j in range(0xFF + 1):
        chi = ((j + 0xCC ) & 0xff) ^ r0
        if(chi == another_secret[i]):
            right_input_rc4d.append(j)
    # Do not write as r0 = ~r0
    r0 = (~ r0) & 0xff

print(','.join([hex(i) for i in right_input_rc4d]))
#0x23,0x8c,0xbe,0xfd,0x25,0xd7,0x65,0xf4,0xb6,0xb3,0xb6,0xf,0xe1,0x74,0xa2,0xef,0xfc,0x38,0x4e,0xd2,0x1a,0x4a,0xb1,0x10,0x96,0xa5



# idapython
# call vm
rc4ed = [0x23,0x8c,0xbe,0xfd,0x25,0xd7,0x65,0xf4,0xb6,0xb3,0xb6,0xf,0xe1,0x74,0xa2,0xef,0xfc,0x38,0x4e,0xd2,0x1a,0x4a,0xb1,0x10,0x96,0xa5]
rcx = idc.GetRegValue('rcx')
i = 0
for addr in range(rcx, rcx + 0x1A):
    idc.PatchByte(addr, rc4ed[i])
    i = i + 1
