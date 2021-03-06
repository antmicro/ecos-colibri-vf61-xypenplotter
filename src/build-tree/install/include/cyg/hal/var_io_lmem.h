#ifndef CYGONCE_HAL_VAR_IO_LMEM_H
#define CYGONCE_HAL_VAR_IO_LMEM_H
//===========================================================================
//
//      var_io_lmem.h
//
//      Vybrid Local memory controller specific registers
//
//===========================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####                                            
// -------------------------------------------                              
// This file is part of eCos, the Embedded Configurable Operating System.   
// Copyright (C) 2012 Free Software Foundation, Inc.                        
//
// eCos is free software; you can redistribute it and/or modify it under    
// the terms of the GNU General Public License as published by the Free     
// Software Foundation; either version 2 or (at your option) any later      
// version.                                                                 
//
// eCos is distributed in the hope that it will be useful, but WITHOUT      
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or    
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    
// for more details.                                                        
//
// You should have received a copy of the GNU General Public License        
// along with eCos; if not, write to the Free Software Foundation, Inc.,    
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.            
//
// As a special exception, if other files instantiate templates or use      
// macros or inline functions from this file, or you compile this file      
// and link it with other works to produce a work based on this file,       
// this file does not by itself cause the resulting work to be covered by   
// the GNU General Public License. However the source code for this file    
// must still be made available in accordance with section (3) of the GNU   
// General Public License v2.                                               
//
// This exception does not invalidate any other reasons why a work based    
// on this file might be covered by the GNU General Public License.         
// -------------------------------------------                              
// ####ECOSGPLCOPYRIGHTEND####                                              
//===========================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):    Antmicro Ltd <contact@antmicro.com>
// Based on:	 {...}/hal/packages/cortexm/kinetis/var/current/include/var_io_lmem.h
// Date:         2014-03-28
// Purpose:       Vybrid variant specific registers
// Description:
// Usage:         #include <cyg/hal/var_io_lmem.h>  // var_io.h includes this file
//
//####DESCRIPTIONEND####
//
//===========================================================================

//----------------------------------------------------------------------------
// LMEM - Local memory controller

typedef volatile struct cyghwr_hal_vybrid_lmem_s {
    cyg_uint32 ccr;    // PC bus Cache control register
    cyg_uint32 clcr;   // PC bus Cache line control register
    void *csar;        // PC bus Cache search address register
    cyg_uint32 cvr;    // PC bus Cache read/write value register
} cyghwr_hal_vybrid_lmem_t;

#define CYGHWR_HAL_VYBRID_LMEM_PC_P  ((cyghwr_hal_vybrid_lmem_t *) 0xE0082000)
#define CYGHWR_HAL_VYBRID_LMEM_PS_P  ((cyghwr_hal_vybrid_lmem_t *) 0xE0082800)

// CCR Bit Fields
#define CYGHWR_HAL_VYBRID_LMEM_CCR_ENCACHE_M          0x00000001
#define CYGHWR_HAL_VYBRID_LMEM_CCR_ENWRBUF_M          0x00000002
#define CYGHWR_HAL_VYBRID_LMEM_CCR_PCCR2        	  0x00000004
#define CYGHWR_HAL_VYBRID_LMEM_CCR_PCCR3         	  0x00000008
#define CYGHWR_HAL_VYBRID_LMEM_CCR_INVW0_M            0x01000000
#define CYGHWR_HAL_VYBRID_LMEM_CCR_PUSHW0_M           0x02000000
#define CYGHWR_HAL_VYBRID_LMEM_CCR_INVW1_M            0x04000000
#define CYGHWR_HAL_VYBRID_LMEM_CCR_PUSHW1_M           0x08000000
#define CYGHWR_HAL_VYBRID_LMEM_CCR_GO_M               0x80000000

//CLCR Bit Fields
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_LGO_M             0x00000001
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_CACHEADDR_M       0x00000FFC
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_CACHEADDR_S       2
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_CACHEADDR(_ca_)   ((_ca_) << CYGHWR_HAL_VYBRID_LMEM_CLCR_CACHEADDR_S)
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_WSEL_M            0x00004000
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_TDSEL_M           0x00010000
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_LCIVB_M           0x00100000
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_LCIMB_M           0x00200000
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_LCWAY_M           0x00400000
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_LCMD_M            0x03000000
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_LCMD_S            24
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_LCMD(_cmd_)       ((_cmd_) << CYGHWR_HAL_VYBRID_LMEM_CLCR_LCMD_S)
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_LCMD_SRCH         0
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_LCMD_INVAL        1
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_LCMD_PUSH         2
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_LCMD_CLR          3
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_LADSEL_M          0x04000000
#define CYGHWR_HAL_VYBRID_LMEM_CLCR_LACC_M            0x08000000

// CSAR Bit Fields
#define CYGHWR_HAL_VYBRID_LMEM_CSAR_LGO_M             0x00000001
#define CYGHWR_HAL_VYBRID_LMEM_CSAR_PHYADDR_M         0xFFFFFFFC
#define CYGHWR_HAL_VYBRID_LMEM_CSAR_PHYADDR_S         2
#define CYGHWR_HAL_VYBRID_LMEM_CSAR_PHYADDR(_adr_)    ((_adr_) << CYGHWR_HAL_VYBRID_LMEM_CSAR_PHYADDR_S)

// CCVR Bit Fields
#define CYGHWR_HAL_VYBRID_LMEM_CCVR_DATA_M            0xFFFFFFFF

#define HAL_CORTEXM_VYBRID_CACHE_PC_ENABLE() \
            hal_cortexm_vybrid_cache_enable(CYGHWR_HAL_VYBRID_LMEM_PC_P)

#define HAL_CORTEXM_VYBRID_CACHE_PS_ENABLE() \
            hal_cortexm_vybrid_cache_enable(CYGHWR_HAL_VYBRID_LMEM_PS_P)

#define HAL_CORTEXM_VYBRID_CACHE_PC_DISABLE() \
            hal_cortexm_vybrid_cache_disable(CYGHWR_HAL_VYBRID_LMEM_PC_P)

#define HAL_CORTEXM_VYBRID_CACHE_PS_DISABLE() \
            hal_cortexm_vybrid_cache_disable(CYGHWR_HAL_VYBRID_LMEM_PS_P)

#define HAL_CORTEXM_VYBRID_CACHE_PC_INVALL() \
            hal_cortexm_vybrid_cache_inval(CYGHWR_HAL_VYBRID_LMEM_PC_P)

#define HAL_CORTEXM_VYBRID_CACHE_PS_INVALL() \
            hal_cortexm_vybrid_cache_inval(CYGHWR_HAL_VYBRID_LMEM_PS_P)

#define HAL_CORTEXM_VYBRID_CACHE_PC_SYNC() \
            hal_cortexm_vybrid_cache_sync(CYGHWR_HAL_VYBRID_LMEM_PC_P)

#define HAL_CORTEXM_VYBRID_CACHE_PS_SYNC() \
            hal_cortexm_vybrid_cache_sync(CYGHWR_HAL_VYBRID_LMEM_PS_P)

#define HAL_CORTEXM_VYBRID_CACHE_PC_CLEAR() \
            hal_cortexm_vybrid_cache_clear(CYGHWR_HAL_VYBRID_LMEM_PC_P)

#define HAL_CORTEXM_VYBRID_CACHE_PS_CLEAR() \
            hal_cortexm_vybrid_cache_clear(CYGHWR_HAL_VYBRID_LMEM_PS_P)

#define HAL_CORTEXM_VYBRID_CACHE_PC_IS_ENABLED() \
            hal_cortexm_vybrid_cache_is_enabled(CYGHWR_HAL_VYBRID_LMEM_PC_P)

#define HAL_CORTEXM_VYBRID_CACHE_PS_IS_ENABLED() \
            hal_cortexm_vybrid_cache_is_enabled(CYGHWR_HAL_VYBRID_LMEM_PS_P)

#define HAL_CORTEXM_VYBRID_CACHE_PS_SRCH(_base, _size_) \
        hal_cortexm_vybrid_cache_lines(CYGHWR_HAL_VYBRID_LMEM_PS_P, _base, _size_, \
                                       CYGHWR_HAL_VYBRID_LMEM_CLCR_LCMD_SRCH)

#define HAL_CORTEXM_VYBRID_CACHE_PS_INVALIDATE(_base, _size_) \
        hal_cortexm_vybrid_cache_lines(CYGHWR_HAL_VYBRID_LMEM_PS_P, _base, _size_, \
                                       CYGHWR_HAL_VYBRID_LMEM_CLCR_LCMD_INVAL)

#define HAL_CORTEXM_VYBRID_CACHE_PS_PUSH(_base, _size_) \
        hal_cortexm_vybrid_cache_lines(CYGHWR_HAL_VYBRID_LMEM_PS_P, _base, _size_, \
                                       CYGHWR_HAL_VYBRID_LMEM_CLCR_LCMD_PUSH)

#define HAL_CORTEXM_VYBRID_CACHE_PS_CLR(_base, _size_) \
        hal_cortexm_vybrid_cache_lines(CYGHWR_HAL_VYBRID_LMEM_PS_P, _base, _size_, \
                                       CYGHWR_HAL_VYBRID_LMEM_CLCR_LCMD_CLR)

#define HAL_CORTEXM_VYBRID_CACHE_PC_INVALIDATE(_base, _size_) \
        hal_cortexm_vybrid_cache_lines(CYGHWR_HAL_VYBRID_LMEM_PC_P, _base, _size_, \
                                       CYGHWR_HAL_VYBRID_LMEM_CLCR_LCMD_INVAL)

#define CYGHWR_HAL_VYBRID_CACHE_WAIT(_lmem_p)          \
            while((_lmem_p)->ccr & CYGHWR_HAL_VYBRID_LMEM_CCR_GO_M)

CYGBLD_FORCE_INLINE void
hal_cortexm_vybrid_cache_enable(cyghwr_hal_vybrid_lmem_t* lmem_p)
{
    lmem_p->ccr = ( CYGHWR_HAL_VYBRID_LMEM_CCR_GO_M |
                    CYGHWR_HAL_VYBRID_LMEM_CCR_INVW0_M |
                    CYGHWR_HAL_VYBRID_LMEM_CCR_INVW1_M |
                    CYGHWR_HAL_VYBRID_LMEM_CCR_ENCACHE_M |
                    CYGHWR_HAL_VYBRID_LMEM_CCR_ENWRBUF_M
                   );
    CYGHWR_HAL_VYBRID_CACHE_WAIT(lmem_p);
}

CYGBLD_FORCE_INLINE void
hal_cortexm_vybrid_cache_disable(cyghwr_hal_vybrid_lmem_t* lmem_p)
{
    lmem_p->ccr = 0;
}

CYGBLD_FORCE_INLINE void
hal_cortexm_vybrid_cache_inval(cyghwr_hal_vybrid_lmem_t* lmem_p)
{
    lmem_p->ccr |= ( CYGHWR_HAL_VYBRID_LMEM_CCR_GO_M |
              CYGHWR_HAL_VYBRID_LMEM_CCR_INVW0_M |
              CYGHWR_HAL_VYBRID_LMEM_CCR_INVW1_M
              );
    CYGHWR_HAL_VYBRID_CACHE_WAIT(lmem_p);
}

CYGBLD_FORCE_INLINE void
hal_cortexm_vybrid_cache_store(cyghwr_hal_vybrid_lmem_t* lmem_p)
{
    lmem_p->ccr |= ( CYGHWR_HAL_VYBRID_LMEM_CCR_GO_M |
                     CYGHWR_HAL_VYBRID_LMEM_CCR_PUSHW0_M |
                     CYGHWR_HAL_VYBRID_LMEM_CCR_PUSHW1_M
                    );
    CYGHWR_HAL_VYBRID_CACHE_WAIT(lmem_p);
}

CYGBLD_FORCE_INLINE void
hal_cortexm_vybrid_cache_clear(cyghwr_hal_vybrid_lmem_t* lmem_p)
{
    lmem_p->ccr |= ( CYGHWR_HAL_VYBRID_LMEM_CCR_GO_M |
                    CYGHWR_HAL_VYBRID_LMEM_CCR_INVW0_M |
                    CYGHWR_HAL_VYBRID_LMEM_CCR_INVW1_M |
                    CYGHWR_HAL_VYBRID_LMEM_CCR_PUSHW0_M |
                    CYGHWR_HAL_VYBRID_LMEM_CCR_PUSHW1_M
                   );
    CYGHWR_HAL_VYBRID_CACHE_WAIT(lmem_p);
}

CYGBLD_FORCE_INLINE void
hal_cortexm_vybrid_cache_sync(cyghwr_hal_vybrid_lmem_t* lmem_p)
{
    hal_cortexm_vybrid_cache_store(lmem_p);
    hal_cortexm_vybrid_cache_clear(lmem_p);
}

CYGBLD_FORCE_INLINE bool
hal_cortexm_vybrid_cache_is_enabled(cyghwr_hal_vybrid_lmem_t* lmem_p)
{
    return lmem_p->ccr & CYGHWR_HAL_VYBRID_LMEM_CCR_ENCACHE_M;
}


CYGBLD_FORCE_INLINE void
hal_cortexm_vybrid_cache_lines(cyghwr_hal_vybrid_lmem_t* lmem_p,
                               void* addr_p, cyg_uint32 size,
                               const cyg_uint32 oper)
{
    cyg_uint32 line_k;
    line_k = (((cyg_uint32)addr_p & (HAL_DCACHE_LINE_SIZE-1)) + size) / HAL_DCACHE_LINE_SIZE + 1;

    lmem_p->clcr = CYGHWR_HAL_VYBRID_LMEM_CLCR_LADSEL_M |
                   CYGHWR_HAL_VYBRID_LMEM_CLCR_TDSEL_M  |
                   CYGHWR_HAL_VYBRID_LMEM_CLCR_LCMD(oper);

    addr_p = (void*)((((cyg_uint32) addr_p) & 0xfffffff0) |
                          CYGHWR_HAL_VYBRID_LMEM_CLCR_LGO_M);
    do {
        lmem_p->csar = addr_p;
        while(lmem_p->clcr & CYGHWR_HAL_VYBRID_LMEM_CLCR_LGO_M);
        addr_p = (void*)(((cyg_uint32)addr_p) + HAL_DCACHE_LINE_SIZE);
    } while(--line_k);
}

//-----------------------------------------------------------------------------
// end of var_io_lmem.h
#endif // CYGONCE_HAL_VAR_IO_LMEM_H
