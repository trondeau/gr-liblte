/* -*- c++ -*- */
/*
 * Copyright 2014 Rondeau Research, LLC
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "pbch_impl.h"

namespace gr {
  namespace liblte {

    pbch::sptr
    pbch::make(int nof_prb, int cell_id, lte_cp_t cp)
    {
      return gnuradio::get_initial_sptr
        (new pbch_impl(nof_prb, cell_id, cp));
    }

    /*
     * The private constructor
     */
    pbch_impl::pbch_impl(int nof_prb, int cell_id, lte_cp_t cp)
      : gr::sync_block("pbch",
                       gr::io_signature::make(0, 0, 0),
                       gr::io_signature::make(1, MAX_PORTS_CTRL, sizeof(gr_complex))),
        d_nof_prb(nof_prb), d_cell_id(cell_id), d_cp(cp)
    {
      if(pbch_init(&d_pbch, d_nof_prb, d_cell_id, d_cp)) {
        throw std::runtime_error("Error creating PBCH object");
      }
    }

    /*
     * Our virtual destructor.
     */
    pbch_impl::~pbch_impl()
    {
      pbch_free(&d_pbch);
    }

    int
    pbch_impl::work(int noutput_items,
                    gr_vector_const_void_star &input_items,
                    gr_vector_void_star &output_items)
    {
      const gr_complex *in = (const gr_complex*)input_items[0];
      gr_complex *out = (gr_complex*)output_items[0];

      pbch_mib_t mib;
      cf_t *slot1_symbols[MAX_PORTS_CTRL];

      // Taken from pbch_enodeb.c; make this modifiable in the block
      int slot_n_re = CPNORM_NSYMB * d_nof_prb * RE_X_RB;
      mib.nof_ports = 1;
      mib.nof_prb = 6;
      mib.phich_length = PHICH_NORM;
      mib.phich_resources = R_1;
      mib.sfn = 0;

      pbch_encode(&d_pbch, &mib, slot1_symbols, 1);

      for(int i = 0; i < MAX_PORTS_CTRL; i++) {
        memcpy((gr_complex*)output_items[i], slot1_symbols[i],
               sizeof(gr_complex)*slot_n_re);
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace liblte */
} /* namespace gr */
