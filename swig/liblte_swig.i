/* -*- c++ -*- */

#define LIBLTE_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "liblte_swig_doc.i"

%{
#include "liblte/pbch.h"
%}


%include "liblte/pbch.h"
GR_SWIG_BLOCK_MAGIC2(liblte, pbch);
