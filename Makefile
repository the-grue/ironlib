.PHONY: all clean test install
all clean test install:
	$(MAKE) -C utils $@
	$(MAKE) -C include $@
	$(MAKE) -C src $@

$(V).SILENT:
