/*
 * arch/arm/mach-nuc970/include/mach/regs-ebi.h
 *
 * Copyright (c) 2015 Nuvoton technology corporation
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */

#ifndef __ASM_ARCH_REGS_EBI_H
#define __ASM_ARCH_REGS_EBI_H

#define REG_EBI_CTL		(NUC970_VA_EBI + 0x00)
#define REG_EBI_BNKCTL(x)	(NUC970_VA_EBI + 0x18 + (x) * 0x4)

#define NUC970_EBI_256K		0x00000000
#define NUC970_EBI_512K		0x00010000
#define NUC970_EBI_1M		0x00020000
#define NUC970_EBI_2M		0x00030000
#define NUC970_EBI_4M		0x00040000
#define NUC970_EBI_8M		0x00050000
#define NUC970_EBI_16M		0x00060000
#define NUC970_EBI_32M		0x00070000

#define NUC970_EBI_8BIT		0x00000001
#define NUC970_EBI_16BIT	0x00000002

#define NUC970_EBI_80TYPE_nBE_WRITE	0x00000000
#define NUC970_EBI_80TYPE_nWE_WRITE	0x01000000
#define NUC970_EBI_68TYPE		0x00080000


#define NUC970_EBI_TYPE_MASK 0x01080000
static inline void nuc970_set_ebi_mode(unsigned int bank, unsigned int mode)
{
	__raw_writel((__raw_readl(REG_EBI_CTL) & ~(NUC970_EBI_TYPE_MASK << bank)) | (mode << bank), REG_EBI_CTL);
}

#define NUC970_EBI_ATTRIB_MASK 0xFFFF0003
static inline void nuc970_set_ebi_attrib(unsigned int bank, unsigned int base, unsigned int size, unsigned int width)
{
	__raw_writel((__raw_readl(REG_EBI_BNKCTL(bank)) & ~NUC970_EBI_ATTRIB_MASK) | ((base << 1) & 0xFFF80000) | size | width, REG_EBI_BNKCTL(bank));
}

#define NUC970_EBI_TIMING_MASK 0x00007FFC
static inline void nuc970_set_ebi_timing(unsigned int bank, unsigned int tACC, unsigned int tCOH, unsigned int tACS, unsigned int tCOS)
{	
	__raw_writel((__raw_readl(REG_EBI_BNKCTL(bank)) & ~NUC970_EBI_TIMING_MASK) | (tACC << 11) | (tCOH << 8) | (tACS << 5) | (tCOS << 2), REG_EBI_BNKCTL(bank));
}


#endif /*  __ASM_ARCH_REGS_EBI_H */