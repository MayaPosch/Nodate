# Main Nodate Makefile.
#
# Merely picks the appropriate architecture bundle.

ifndef ARCH
$(error ARCH hasn't been set.)
endif

include arch/$(ARCH)/Makefile
