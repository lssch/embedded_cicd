## Coverage with gcov
To generate a text report:
```
gcovr --gcov-executable arm-none-eabi-gcov .
```
To generate a HTML report (directory gcovr must exist):
```
gcovr --gcov-executable arm-none-eabi-gcov --html-details -o ./gcovr/main.html
```
or use Terminal -> Run Task... -> gcovr