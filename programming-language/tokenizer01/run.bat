@echo off
docker rm tokenizer
docker build . -t tokenizer
docker run --name tokenizer tokenizer
