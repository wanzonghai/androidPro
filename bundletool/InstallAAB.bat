@echo off


set /p input=bundletool_path:
set /p input1=aab_path:
set /p input2=key_path:
set /p input3=alias:
set /p input4=alias password:
set /p input5=key password:




java -jar %input% build-apks --bundle=%input1% --output=game.apks --ks=%input2% --ks-pass=pass:%input5% --ks-key-alias=%input3% --key-pass=pass:%input4%

java -jar %input% install-apks --apks=game.apks
echo finish
pause