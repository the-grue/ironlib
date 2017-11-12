%.a:
	@echo "AR $@"
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	@echo "CC $@"
	$(CC) $(CFLAGS) -c $< -o $@

%: %.o
	@echo "LINK $@"
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)
