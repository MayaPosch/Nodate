# Main Nodate Makefile.
#
# Merely picks the appropriate architecture bundle.

ifndef ARCH
$(error ARCH hasn't been set.)
endif

ifeq ($(NDLANGUAGE),ada)
include arch/$(ARCH)/Makefile.ada
else
include arch/$(ARCH)/Makefile
endif
