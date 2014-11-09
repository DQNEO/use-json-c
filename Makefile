JSON_C_DIR=/opt/json-c
CFLAGS += -I$(JSON_C_DIR)/include
LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c

all:json

json: json.c
	$(CC) $(CFLAGS) $(LDFLAGS) json.c  -o json

.PHONY:clean
clean:
	rm json
