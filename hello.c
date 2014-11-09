/**
 * Sample for using json-c
 * gcc -I /opt/json-c/include -L /opt/json-c/lib -ljson-c hello.c  -o hello
 *
 */
#include <stdio.h>
#include <json-c/json.h>

int main(int argc, char **argv)
{

    char *json_string = "{'a':1,'b':2,'c':3}";
    struct json_object *obj = json_tokener_parse(json_string);

    json_object_object_foreach(obj, key, val) {
        printf("-- \t%s: %s\n", key, json_object_to_json_string(val));
    }
}
