#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"

int main() {
    int argc; // コマンドのトークン数をカウントする
    char cmd[80]; // 80文字のコマンド入力バッファ
    char *cmdp; // 作業用ポインタ
    char *argv[10]; // トークンを入れる配列
    int status;

    for (;;) {
        printf("コマンドを入力してください > ");

        if (fgets(cmd, 80, stdin) == NULL) {
            exit(0);
        }

        cmd[strlen(cmd) - 1] = '\0';
        cmdp = cmd;

        // コマンドをトークンに分解
        for (argc = 0;; argc++) {
            printf("%d\n", argc);
            if ((argv[argc] = strtok(cmdp, " ")) == NULL) {
                break;
            }
            cmdp = NULL;
        }

        // 子プロセスの生成をして、子プロセスをコマンドに変身させる
        if (fork() == 0) {
            execvp(argv[0], argv);

            // ちゃんと exec で着ない場合だけここから下が実行される
            // execに失敗したら、exit(1)で子プロセスを消滅させる && 親プロセスにお知らせする
            printf("コマンドが見つかりませんでした\n");
            exit(1);
        } else {
            wait(&status);
        }
    }
}