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


#ifndef INCLUDED_LIBLTE_PBCH_H
#define INCLUDED_LIBLTE_PBCH_H

#include <liblte/api.h>
#include <gnuradio/sync_block.h>
#include <lte.h>

namespace gr {
  namespace liblte {

    /*!
     * \brief <+description of block+>
     * \ingroup liblte
     *
     */
    class LIBLTE_API pbch : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<pbch> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of liblte::pbch.
       *
       * To avoid accidental use of raw pointers, liblte::pbch's
       * constructor is in a private implementation
       * class. liblte::pbch::make is the public interface for
       * creating new instances.
       */
      static sptr make(int nof_prb, int cell_id, lte_cp_t cp=CPNORM);
    };

  } // namespace liblte
} // namespace gr

#endif /* INCLUDED_LIBLTE_PBCH_H */
