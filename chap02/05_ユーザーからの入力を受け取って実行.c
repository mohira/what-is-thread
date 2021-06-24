#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"

int main() {
    int argc; // コマンドのトークン数をカウントする
    char cmd[80]; // 80文字のコマンド入力バッファ
    char *cmdp; // 作業用ポインタ
    char *argv[10]; // トークンを入れる配列

    printf("コマンドを入力してください > ");

    if (fgets(cmd, 80, stdin) == NULL) {
        exit(0);
    }

    cmd[strlen(cmd) - 1] = '\0'; // 最後の改行文字をNULL文字に変更
    cmdp = cmd;

    for (argc = 0;; argc++) {
        if ((argv[argc] = strtok(cmdp, " ")) == NULL) {
            break;
        }
        cmdp = NULL;
    }

    printf("ex1 は %sに変身します\n", cmd);
    execvp(argv[0], argv);

}