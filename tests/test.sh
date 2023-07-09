#!/bin/sh

for file in ../prog/*; do
    ../clox $file
done