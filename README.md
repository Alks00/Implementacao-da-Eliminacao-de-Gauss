# Implementações da Eliminação de Gauss

Lucas do Prado Szczepaniak
<br><br>
Os códigos foram executados todos no windows 10 sendo compilados e executados no prompt<br>
Para todos os códigos é necessário alterar no arquivo main o valor de N para alterar o tamanho da matriz

# Como usar:
## C
Pelo prompt navegue até a pasta onde está o arquivo main.c e execute <br>
gcc main.c -o main.exe <br>
main.exe

## Golang
Pelo prompt navegue até a pasta onde está o arquivo main.go e execute<br>
go run main.go<br><br>

Caso deseje criar o executavel<br>
go build -o main.exe main.go<br>
main.exe

## Rust
Rust é necessario criar o projeto, pelo prompt na pasta desejada execute<br>
cargo new meu_projeto<br><br>

Após substitua os arquivos cargo.toml na pasta projeto e o arquivo main.rs na pasta src pelos respectivos arquivos disponibilizados<br><br>

O Rust possui duas formas de execução uma otimizada e uma não otimizada<br><br>

Não otimizada:<br>
Dentro da pasta projeto pelo prompt execute<br>
cargo run<br><br>

Otimizada:<br>
Dentro da pasta projeto pelo prompt execute<br>
cargo build --release<br>
target\release\meu_projeto.exe<br>
cd target\release<br>
meu_projeto.exe
