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

#ifndef INCLUDED_LIBLTE_PBCH_IMPL_H
#define INCLUDED_LIBLTE_PBCH_IMPL_H

#include <liblte/pbch.h>

namespace gr {
  namespace liblte {

    class pbch_impl : public pbch
    {
     private:
      int d_nof_prb;
      int d_cell_id;
      lte_cp_t d_cp;
      pbch_t d_pbch;

     public:
      pbch_impl(int nof_prb, int cell_id, lte_cp_t cp=CPNORM);
      ~pbch_impl();

      // Where all the action really happens
      int work(int noutput_items,
	       gr_vector_const_void_star &input_items,
	       gr_vector_void_star &output_items);
    };

  } // namespace liblte
} // namespace gr

#endif /* INCLUDED_LIBLTE_PBCH_IMPL_H */
