/**
 * gcc -I /opt/json-c/include -L /opt/json-c/lib -ljson-c role.c  -o role
 *
 * Usage:
 *  ./role  file.json
 */
#include <stdio.h>
#include <string.h>
#include <json-c/json.h>

/**
 * credentialsをまとめて持つ構造体
 * iam roleで与えられるcredentialsはアクセスキーと
 * シークレットキーのペア以外にもセキュリティトークンがある
 */
struct Credentials {
    const char* accesskeyid;
    const char* secretaccesskey;
    const char* token;
};

int main(int argc, char **argv) {
    struct json_object *obj = json_object_from_file(argv[1]);

    struct Credentials crd;

    json_object_object_foreach(obj, key, val) {
        if (strcmp(key, "AccessKeyId") == 0) {
            crd.accesskeyid = json_object_to_json_string(val);
        } else if (strcmp(key, "SecretAccessKey") == 0) {
            crd.secretaccesskey = json_object_to_json_string(val);
        } else if (strcmp(key, "Token") == 0) {
            crd.token = json_object_to_json_string(val);
        }
    }

    printf("%s\n", crd.accesskeyid);
    printf("%s\n", crd.secretaccesskey);
    printf("%s\n", crd.token);
    return 0;
}
