/**************************************************************************
 *                                                                        *
 *  Edge Detect Design Walkthrough for HLS                                *
 *                                                                        *
 *  Software Version: 1.0                                                 *
 *                                                                        *
 *  Release Date    : Tue Jan 14 15:40:43 PST 2020                        *
 *  Release Type    : Production Release                                  *
 *  Release Build   : 1.0.0                                               *
 *                                                                        *
 *  Copyright 2020, Mentor Graphics Corporation,                          *
 *                                                                        *
 *  All Rights Reserved.                                                  *
 *  
 **************************************************************************
 *  Licensed under the Apache License, Version 2.0 (the "License");       *
 *  you may not use this file except in compliance with the License.      * 
 *  You may obtain a copy of the License at                               *
 *                                                                        *
 *      http://www.apache.org/licenses/LICENSE-2.0                        *
 *                                                                        *
 *  Unless required by applicable law or agreed to in writing, software   * 
 *  distributed under the License is distributed on an "AS IS" BASIS,     * 
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or       *
 *  implied.                                                              * 
 *  See the License for the specific language governing permissions and   * 
 *  limitations under the License.                                        *
 **************************************************************************
 *                                                                        *
 *  The most recent version of this package is available at github.       *
 *                                                                        *
 *************************************************************************/
#ifndef __INCLUDED_ram_1k_16_sp_H__
#define __INCLUDED_ram_1k_16_sp_H__

// SystemC memory model of ram_1k_16_sp
// Generated by Catapult memory generator
// Generated by:   michaelf
// Generated date: Wed Oct  2 11:14:08 2019

// The following classes have been defined:
//     class ram_1k_16_sp a 0 delay "structural" model of the RAM

//     class ram_1k_16_sp_model<TLM/SYN>::mem<T,size,TLM/SYN>
//         A memory model that can be instanced and used for simulation and synthesis

//     class ram_1k_16_sp_model<TLM/SYN>::port_0_port<T,size,TLM/SYN>
//         a model of an external port with read/write capability

#include <ccs_types.h>
#ifndef NO_ASSERTS
#include <assert.h>
#endif

#pragma map_to_operator ram_1k_16_sp
template <
  int ram_id,
  int data_width,
  int addr_width,
  int depth>
class ram_1k_16_sp : public sc_module
{
public:
  sc_in< sc_lv<addr_width> >   addr;
  sc_in< sc_lv<data_width> >   d;
  sc_in< bool >   chip_en;
  sc_in< bool >   wr_en;
  sc_in< bool >   rd_en;
  sc_in< bool >   clk;
  sc_out< sc_lv<data_width> >   q;

#if !defined(__SYNTHESIS__)
  sc_signal<sc_lv<data_width> > mem[depth];
#endif

  SC_CTOR(ram_1k_16_sp) :
    addr("addr")
    ,d("d")
    ,chip_en("chip_en")
    ,wr_en("wr_en")
    ,rd_en("rd_en")
    ,clk("clk")
    ,q("q")
  {
    SC_METHOD(seq_proc_1);
    dont_initialize();
    sensitive << clk.pos();
  }

  void seq_proc_1() {
#if !defined(__SYNTHESIS__)
    if ( chip_en.read() ) {
      int address;
      // write X
      if ((chip_en==1) && (wr_en==1)) {
        vector_to_type( addr.read(), false, &address );
#if !defined(NO_ASSERTS) && !defined(__SYNTHESIS__)
        assert( address>=0 && address <depth );
#endif
        mem[address] = d.read();
      }

      // read
      if ( (rd_en==1) ) {
        vector_to_type( addr.read(), false, &address );
#if !defined(NO_ASSERTS) && !defined(__SYNTHESIS__)
        assert( address>=0 && address <depth );
#endif
        q.write( mem[address] );
      }
      else q.write( sc_lv< data_width>() );

      // write
      if ((chip_en==1) && (wr_en==1)) {
        vector_to_type( addr.read(), false, &address );
#if !defined(NO_ASSERTS) && !defined(__SYNTHESIS__)
        assert( address>=0 && address <depth );
#endif
        mem[address] = d.read();
      }

    }
#endif
  }

#if !defined(__SYNTHESIS__)
  // NOTE: this method is intended for use by testbenches only. It is not synthesizable!
  sc_lv< data_width> tb_read( int address ) const {
#ifndef NO_ASSERTS
    assert( address>=0 && address < depth);
#endif
    return mem[address];
  }

  // NOTE: this method is intended for use by testbenches only. It is not synthesizable!
  void tb_write( int address, sc_lv<data_width> data ) {
#ifndef NO_ASSERTS
    assert( address>=0 && address < depth);
#endif
    mem[address] = data;
  }

#endif
};

template <abstraction_t source_abstraction = AUTO>
class ram_1k_16_sp_model {
public:
#if defined(__SYNTHESIS__)
  template <class T, unsigned int size, abstraction_t impl_abstraction = SYN> class mem{};
private:
  template <class T, unsigned int size, abstraction_t impl_abstraction = SYN> class port_0_local;
public:
  template <class T, unsigned int size, abstraction_t impl_abstraction = SYN> class port_0_port;

#elif defined (CCS_DUT_CYCLE) || defined (CCS_DUT_RTL)
  template <class T, unsigned int size, abstraction_t impl_abstraction = (source_abstraction==AUTO) ? SYN : source_abstraction>
      class mem{};
private:
  template <class T, unsigned int size, abstraction_t impl_abstraction = (source_abstraction==AUTO) ? SYN : source_abstraction>
      class port_0_local;
public:
  template <class T, unsigned int size, abstraction_t impl_abstraction = (source_abstraction==AUTO) ? SYN : source_abstraction>
      class port_0_port;

#else
  template <class T, unsigned int size, abstraction_t impl_abstraction = (source_abstraction==AUTO) ? P2P_DEFAULT_VIEW
      : source_abstraction> class mem{};
private:
  template <class T, unsigned int size, abstraction_t impl_abstraction = (source_abstraction==AUTO) ? P2P_DEFAULT_VIEW
      : source_abstraction> class port_0_local;
public:
  template <class T, unsigned int size, abstraction_t impl_abstraction = (source_abstraction==AUTO) ? P2P_DEFAULT_VIEW
      : source_abstraction> class port_0_port;

#endif

  // ***********************************************
  // TLM TLM TLM TLM TLM TLM TLM TLM TLM TLM TLM TLM
  //    This code is only for TLM simulation only
  // ***********************************************

  template <class T, unsigned int size>
  class mem <T,size,TLM>
  {
    enum {
      addr_width = nbits<size-1>::val,
      signedtype = mc_typedef_T_traits<T>::issigned,
      data_width = mc_typedef_T_traits<T>::bitwidth
    };
  public:
    T readwrite (bool en_write, ac_int<addr_width,false> addr, T data=0) {
      port_0_port_instance.reset_chk.test();
#ifndef NO_ASSERTS
      assert( addr>=0 && addr<size );
#endif
      T temp = array[addr];
      if (en_write ) {
        array[addr] = data;
      }
      return temp;
    };

    void write (ac_int<addr_width,false> addr, T data=0) {
      port_0_port_instance.reset_chk.test();
#ifndef NO_ASSERTS
      assert( addr>=0 && addr<size );
#endif
      array[addr] = data;
    };

    T read ( ac_int<addr_width,false> addr ) {
#ifndef NO_ASSERTS
      assert( addr>=0 && addr<size );
#endif
      return array[addr];
    }

    T &operator [] (int index) {
#ifndef NO_ASSERTS
      assert( index>=0 && index<size );
#endif
      return array[index];
    }

    const T &operator [] (int index) const {
#ifndef NO_ASSERTS
      assert( index>=0 && index<size );
#endif
      return array[index];
    }

    // NOTE: this method is intended for use by testbenches only. It is not synthesizable!
    T tb_read( int address ) const {
#ifndef NO_ASSERTS
      assert( address>=0 && address <size );
#endif
      return array[address];
    }

    // NOTE: this method is intended for use by testbenches only. It is not synthesizable!
    void tb_write( int address, T data ) {
#ifndef NO_ASSERTS
      assert( address>=0 && address <size );
#endif
      array[address] = data;
    }

  public:
    mem(const char* name)
      : port_0_port_instance(*this, ccs_concat(name,"port_0"))
      {}

    void reset() {
      port_0_port_instance.reset();
    }

    void chip_en(sc_in<bool> &chip_en_arg) {}
    void chip_en(sc_signal<bool> &chip_en_arg) {}

    void clk(sc_in<bool> &clk_arg) {
      port_0_port_instance.clock_ok();
    }
    void clk(sc_signal<bool> &clk_arg) {
      port_0_port_instance.clock_ok();
    }

    port_0_local<T,size,TLM> port_0_port_instance;
  private:
    T array[size];
    friend class port_0_local<T,size,TLM>;
  };

private:
  template <class T, unsigned int size>
  class port_0_local<T,size,TLM>
  {
    enum {
      addr_width = nbits<size-1>::val,
      signedtype = mc_typedef_T_traits<T>::issigned,
      data_width = mc_typedef_T_traits<T>::bitwidth
    };
    p2p_checker reset_chk;
    p2p_checker clock_chk;
    void clock_ok() {clock_chk.ok();}

  public:
    port_0_local (mem<T,size,TLM> &my_parent, const char *name)
      : reset_chk( name, "call reset()", "access this memory")
      , clock_chk( name, "bind the clock port", "access this memory")
      , parent(my_parent)
      {}

    void reset() {reset_chk.ok();}

    T &operator [] (int index) {
      reset_chk.test();
      clock_chk.test();
      return parent.array[index];
    }

    const T &operator [] (int index) const {
      reset_chk.test();
      clock_chk.test();
#ifndef NO_ASSERTS
      assert( index>=0 && index<size );
#endif
      return parent.array[index];
    }

    T readwrite (bool en_write, ac_int<addr_width,false> addr, T data=0) {
      reset_chk.test();
      clock_chk.test();
#ifndef NO_ASSERTS
      assert( addr>=0 && addr<size );
#endif
      T temp = parent.array[addr];
      if (en_write ) {
        parent.array[addr] = data;
      }
      return temp;
    };

    void write (ac_int<addr_width,false> addr, T data=0) {
      reset_chk.test();
      clock_chk.test();
#ifndef NO_ASSERTS
      assert( addr>=0 && addr<size );
#endif
      parent.array[addr] = data;
    };

    T read ( ac_int<addr_width,false> addr ) {
      reset_chk.test();
      clock_chk.test();
#ifndef NO_ASSERTS
      assert( addr>=0 && addr<size );
#endif
      return parent.read(addr);
    }

  private:
    mem<T,size,TLM> &parent;
    friend class mem<T,size,TLM>;
  };

public:
  template <class T, unsigned int size>
  class port_0_port<T,size,TLM>
  {
    enum {
      addr_width = nbits<size-1>::val,
      signedtype = mc_typedef_T_traits<T>::issigned,
      data_width = mc_typedef_T_traits<T>::bitwidth
    };
    p2p_checker reset_chk;

  public:
    port_0_port(const char *name)
      : reset_chk(name, "call reset()", "access this port")
      , chan_ptr(0)
      , port_ptr(0)
      {}

    T readwrite(bool write, unsigned int addr, T data ) {
      reset_chk.test();
      if ( bound_to_port )
        return port_ptr->readwrite(write,addr,data);
      else
        return chan_ptr->readwrite(write,addr,data);
    }

    void write(unsigned int addr, T data ) {
      reset_chk.test();
      if ( bound_to_port )
        port_ptr->write(addr,data);
      else
        chan_ptr->write(addr,data);
    }

    T read(unsigned int addr) {
      reset_chk.test();
      if ( bound_to_port )
        return port_ptr->read(addr);
      else
        return chan_ptr->read(addr);
    }

    T &operator [] (int index) {
      reset_chk.test();
      return (bound_to_port? (*port_ptr)[index] : (*chan_ptr)[index]);
    }

    void reset() {reset_chk.ok();}

    void operator() (port_0_local<T,size,TLM> &c) {
      chan_ptr = &c;
      c.reset(); // Supress reset error on bound memory
      bound_to_port = false;
    }

    void operator() (port_0_port<T,size,TLM> &c) {
      port_ptr = &c;
      c.reset(); // Supress reset error on bound port
      bound_to_port = true;
    }

    void operator() (mem<T,size,TLM> &m) {
      chan_ptr = &m.port_0_port_instance;
      chan_ptr->reset(); // Supress reset error on bound memory
      bound_to_port = false;
    }

  private:
    bool bound_to_port;
    port_0_local<T,size,TLM> *chan_ptr;
    port_0_port<T,size,TLM> *port_ptr;
  };

  // ***********************************************
  // SYN SYN SYN SYN SYN SYN SYN SYN SYN SYN SYN SYN
  // Synthesis code
  // ***********************************************

private:
  template <class T, unsigned int size>
  class port_0_local<T,size,SYN>
  {
    enum {
      addr_width = nbits<size-1>::val,
      signedtype = mc_typedef_T_traits<T>::issigned,
      data_width = mc_typedef_T_traits<T>::bitwidth
    };
    p2p_checker reset_chk;
    p2p_checker clock_chk;
    class mem_ref
    {
    public:
      mem_ref( port_0_local<T,size,SYN> &my_parent, ac_int<addr_width,false> addr)
      : address(addr), parent(my_parent) {}

      operator T() const { return parent.read(address); }

      inline mem_ref operator = ( T val ) {
        parent.write(address,val);
        return *this;
      }

      inline mem_ref operator = ( const mem_ref &val ) { return operator = ((T)val); }

    private:
      ac_int<addr_width,false> address;
      port_0_local<T,size,SYN> &parent;
    };

    void clock_ok() {clock_chk.ok();}

  public:
    port_0_local( const char *name)
      : reset_chk( name, "call reset()", "access this memory")
      , clock_chk( name, "bind the clock port", "access this memory")
      , addr(ccs_concat(name,"addr"))
      , d(ccs_concat(name,"d"))
      , wr_en(ccs_concat(name,"wr_en"))
      , rd_en(ccs_concat(name,"rd_en"))
      , q(ccs_concat(name,"q"))
      {}

    #pragma remove_out_reg
    #pragma design modulario
    T readwrite (bool en_write, ac_int<addr_width,false> addr, T data=0) {
      reset_chk.test();
      clock_chk.test();
      sc_lv<data_width> temp_data;
      type_to_vector(data, (signedtype?true:false), temp_data);
      sc_lv<addr_width> temp_addr;
      type_to_vector(addr, (signedtype?true:false), temp_addr);
      if (en_write) {
        wr_en.write(1);
      } else {
        wr_en.write(0);
      }
      rd_en.write(1);
      addr.write( temp_addr );
      d.write( temp_data );
      #pragma unroll
      for (int lcnt=0; lcnt<1; lcnt++) wait();
#if defined(CALYPTO_SC)
      wait(); // Account for unreg outputs for SLEC
#elif !defined(__SYNTHESIS__)
      wait(0.3, SC_NS);  // Account for unreg outputs in simulation
#endif
      wr_en.write(0);
      rd_en.write(0);
#if !defined(CALYPTO_SC)
      // Return outputs to don't care to save area
      sc_lv<data_width> dc;
      d.write( dc );
      addr.write( dc );
#endif
      T return_data;
      vector_to_type(q.read(), (signedtype?true:false), &return_data);
      return return_data;
    }

    void write ( ac_int<addr_width,false> addr, T data ) {
      readwrite(true,addr,data);
    }

    T read ( ac_int<addr_width,false> addr ) {
      return readwrite(false,addr);
    }

    mem_ref operator [] (int index) {
      mem_ref write_ref(*this, index);
      return write_ref;
    }

    void reset() {
      wr_en.write(0);
      rd_en.write(0);
      addr.write(sc_dt::Log_0);
      d.write(sc_dt::Log_0);
      reset_chk.ok();
    }

    sc_signal< sc_lv<addr_width> > addr;
    sc_signal< sc_lv<data_width> > d;
    sc_signal< bool > wr_en;
    sc_signal< bool > rd_en;
    sc_signal< sc_lv<data_width> > q;
  private:
    friend class mem<T,size,SYN>;
  };

public:
  template <class T, unsigned int size>
  class mem <T,size,SYN>
  {
    enum {
      addr_width = nbits<size-1>::val,
      signedtype = mc_typedef_T_traits<T>::issigned,
      data_width = mc_typedef_T_traits<T>::bitwidth
    };
    class mem_ref
    {
    public:
      mem_ref( mem<T,size,SYN> &my_parent, ac_int<addr_width,false> addr)
      : address(addr), parent(my_parent) {}

      operator T() const { return parent.read(address); }

      inline mem_ref operator = ( T val ) {
        parent.write(address,val);
        return *this;
      }

      inline mem_ref operator = ( const mem_ref &val ) { return operator = ((T)val); }

    private:
      ac_int<addr_width,false> address;
      mem<T,size,SYN> &parent;
    };

  public:
    mem ( const char *name)
      : RAM(ccs_concat(name, "RAM"))
      , port_0_port_instance(ccs_concat(name,"port_0"))
    {
      RAM.addr(port_0_port_instance.addr);
      RAM.d(port_0_port_instance.d);
      RAM.wr_en(port_0_port_instance.wr_en);
      RAM.rd_en(port_0_port_instance.rd_en);
      RAM.q(port_0_port_instance.q);
    }

    port_0_local<T,size,SYN> port_0_port_instance;

    void chip_en(sc_in<bool> &chip_en_arg) {
      RAM.chip_en(chip_en_arg);
    }
    void chip_en(sc_signal<bool> &chip_en_arg) {
      RAM.chip_en(chip_en_arg);
    }

    void clk(sc_in<bool> &clk_arg) {
      RAM.clk(clk_arg);
      port_0_port_instance.clock_ok();
    }
    void clk(sc_signal<bool> &clk_arg) {
      RAM.clk(clk_arg);
      port_0_port_instance.clock_ok();
    }


    T read ( ac_int<addr_width,false> addr ) {
      return port_0_port_instance.read( addr );
    }

    void write (ac_int<addr_width,false> addr, T data=0) {
      port_0_port_instance.write( addr, data );
    }

    T readwrite (bool en_write, ac_int<addr_width,false> addr, T data=0) {
      return port_0_port_instance.readwrite( en_write, addr, data );
    }

    mem_ref operator [] (int index) {
      mem_ref write_ref(*this, index);
      return write_ref;
    }

    void reset() {
      port_0_port_instance.reset();
    }

    // NOTE: this method is intended for use by testbenches only. It is not synthesizable!
    T tb_read(int address) const {
#ifndef NO_ASSERTS
      assert( address>=0 && address<size );
#endif
      T return_data;
      vector_to_type( RAM.tb_read(address) , (signedtype?true:false), &return_data);
      return return_data;
    }

    // NOTE: this method is intended for use by testbenches only. It is not synthesizable!
    void tb_write( int address, T val) {
#ifndef NO_ASSERTS
      assert( address>=0 && address<size );
#endif
      sc_lv<data_width> temp_data;
      type_to_vector(val, (signedtype?true:false), temp_data);
      RAM.tb_write(address, temp_data);
    }

  private:
    ram_1k_16_sp<0, data_width, addr_width, size> RAM;
  };

  template <class T, unsigned int size>
  class port_0_port<T,size,SYN>
  {
    enum {
      addr_width = nbits<size-1>::val,
      signedtype = mc_typedef_T_traits<T>::issigned,
      data_width = mc_typedef_T_traits<T>::bitwidth
    };
    p2p_checker reset_chk;

    class mem_ref
    {
    public:
      mem_ref( port_0_port<T,size,SYN> &my_parent, ac_int<addr_width,false> addr)
      : address(addr), parent(my_parent) {}

      operator T() const { return parent.read(address); }

      inline mem_ref operator = ( T val ) {
        parent.write(address,val);
        return *this;
      }

      inline mem_ref operator = ( const mem_ref &val ) { return operator = ((T)val); }

    private:
      ac_int<addr_width,false> address;
      port_0_port<T,size,SYN> &parent;
    };

  public:
    port_0_port( const char *name)
      : reset_chk( name, "call reset()", "access this memory")
      , addr(ccs_concat(name,"addr"))
      , d(ccs_concat(name,"d"))
      , wr_en(ccs_concat(name,"wr_en"))
      , rd_en(ccs_concat(name,"rd_en"))
      , q(ccs_concat(name,"q"))
      {}

    #pragma remove_out_reg
    #pragma design modulario
    T readwrite (bool en_write, ac_int<addr_width,false> addr, T data=0) {
      reset_chk.test();
      sc_lv<data_width> temp_data;
      type_to_vector(data, (signedtype?true:false), temp_data);
      sc_lv<addr_width> temp_addr;
      type_to_vector(addr, (signedtype?true:false), temp_addr);
      if (en_write) {
        wr_en.write(1);
      } else {
        wr_en.write(0);
      }
      rd_en.write(1);
      addr.write( temp_addr );
      d.write( temp_data );
      #pragma unroll
      for (int lcnt=0; lcnt<1; lcnt++) wait();
#if defined(CALYPTO_SC)
      wait(); // Account for unreg outputs for SLEC
#elif !defined(__SYNTHESIS__)
      wait(0.3, SC_NS);  // Account for unreg outputs in simulation
#endif
      wr_en.write(0);
      rd_en.write(0);
#if !defined(CALYPTO_SC)
      // Return outputs to don't care to save area
      sc_lv<data_width> dc;
      d.write( dc );
      addr.write( dc );
#endif
      T return_data;
      vector_to_type(q.read(), (signedtype?true:false), &return_data);
      return return_data;
    }

    void write ( ac_int<addr_width,false> addr, T data ) {
      readwrite(true,addr,data);
    }

    T read ( ac_int<addr_width,false> addr ) {
      return readwrite(false,addr);
    }

    void reset() {
      wr_en.write(0);
      rd_en.write(0);
      addr.write(sc_dt::Log_0);
      d.write(sc_dt::Log_0);
      reset_chk.ok();
    }

    sc_out< sc_lv<addr_width> > addr;
    sc_out< sc_lv<data_width> > d;
    sc_out< bool > wr_en;
    sc_out< bool > rd_en;
    sc_in< sc_lv<data_width> > q;

    mem_ref operator [] (int index) {
      mem_ref write_ref(*this, index);
      return write_ref;
    }

    template <class C> void bind( C &c ) {
      addr(c.addr);
      d(c.d);
      wr_en(c.wr_en);
      rd_en(c.rd_en);
      q(c.q);
    }

    template <class C> void operator() (C& c) {
      bind(c);
    }

    void operator() (mem<T,size,SYN> &m) {
      addr(m.port_0_port_instance.addr);
      d(m.port_0_port_instance.d);
      wr_en(m.port_0_port_instance.wr_en);
      rd_en(m.port_0_port_instance.rd_en);
      q(m.port_0_port_instance.q);
    }

  };

};
#endif // ifndef __INCLUDED_ram_1k_16_sp_H__


