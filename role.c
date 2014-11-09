/**
 * gcc -I /opt/json-c/include -L /opt/json-c/lib -ljson-c role.c  -o role
 *
 * Usage:
 *  ./role  file.json
 */
#include <stdio.h>
#include <json-c/json.h>

void dump_json(struct json_object* const obj) {
    json_object_object_foreach(obj, key, val) {
        printf("-- \t%s: %s\n", key, json_object_to_json_string(val));
    }
}

int main(int argc, char **argv) {
    struct json_object *obj2 = json_object_from_file(argv[1]);
    dump_json(obj2);
    return 0;
}
