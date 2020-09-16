#Компилирует и запускает прогу с тестовыми файлами
rm *.out; cd libft; make ; cd .. ; gcc src/main/main.c src/params/* src/print/* src/algo/* -Iincl -Llibft -lftprintf; ./a.out