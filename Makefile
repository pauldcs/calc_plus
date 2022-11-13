include calc_plus.mak

SRCS_OBJS := $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	@mkdir -vp $(dir $@)
	$(CC) $(CFLAGS) -g3 -MMD -MP -o $@ -c $< -I $(INCS_DIR)

all: $(NAME)

-include  $(SRCS_OBJS:.o=.d)

$(NAME): $(SRCS_OBJS)
	$(MAKE) -C srcs/libstringf
	$(CC) $(LBSD) $(CFLAGS) $^ -o $(NAME) -L srcs/libstringf -lstringf

test: all
	@bash tester/tester.sh

clean:
	rm -f $(SRCS_OBJS)

fclean: clean
	$(MAKE) fclean -C srcs/libstringf
	rm -f $(NAME)
	rm -rf $(OBJS_DIR)

re: fclean all

.PHONY	: all clean fclean re