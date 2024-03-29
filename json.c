/**
 * Sample for using json-c
 * gcc -I /opt/json-c/include -L /opt/json-c/lib -ljson-c json.c  -o json
 *
 * Usage:
 *  ./json sample.json
 */
#include <stdio.h>
#include <json-c/json.h>

void dump_json(struct json_object* const obj) {
    json_object_object_foreach(obj, key, val) {
        printf("-- \t%s: %s\n", key, json_object_to_json_string(val));
    }
}

int main(int argc, char **argv) {
    puts("\n== json parse from srting");
    struct json_object *obj1 = json_tokener_parse("{'a':1,'b':2,'c':3}");
    dump_json(obj1);

    puts("\n== json parse from file");
    struct json_object *obj2 = json_object_from_file(argv[1]);
    dump_json(obj2);
    return 0;
}
