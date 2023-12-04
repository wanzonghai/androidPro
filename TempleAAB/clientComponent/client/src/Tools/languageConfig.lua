local languageConfig = {
    ["bx"] = {
        ["network_delay"]= {"Sua rede está um pouco atrasada"},
        ["network_timeout"]= {"Erro de rede, tente depois novamente"},
        ["operate_success"]={"Operação bem-sucedida!"},
        ["input_money"]= {"Insira o montante primeiro"},
        ["input_error_money"]= {"Erro de montante inserido"},
        ["user_score_less"]= {"Não há moedas de ouro suficientes!"},
        ["bank_score_less"]= {"Não há moedas de ouro suficientes no banco!"},
        ["old_bankpsd_empty"]={"A senha antiga do banco não pode ficar vazia!"},
        ["old_bankpsd_error"]={"Senha antiga do banco inserida incorretamente!"},
        ["new_bankpsd_empty"]={"A nova senha do banco não pode ficar vazia!"},
        ["two_bankpsd_notequal"]={"As duas senhas são inconsistentes"},
        ["bankpsd_modify_success"]={"Senha do banco alterada com sucesso!"},
        ["bank_transfer_tips"]={"No momento, você não pode usar esta função, entre em contato com o atendimento ao cliente para obter detalhes!"},
        ["input_psd_empty"]={"A entrada de senha está vazia!"},
        ["psd_length_less6"]={"Insira pelo menos 6 caracteres"},
        ["bank_psd_error"]={"Senha do banco digitada incorretamente!"},
        ["input_id_empty"]={"Por favor, insira o ID do jogador"},
        ["input_id_error"]={"Entrada incorreta do ID de transferência!"},
        ["input_money_empty"]={"O valor da transferência não pode ficar vazio!"},
        ["input_money_error"]={"Insira o valor correto da transferência!"},
        ["input_money_toobig"]={"O valor da transferência excede o valor atual do banco!"},
        ["transfer_success"]={"transferência bem sucedida!"},
        ["input_phone_empty"]={"Por favor, insira seu número de celular primeiro!"},
        ["copy_success"]={"Copiado com sucesso!"},
        ["chat_content_empty"]={"Insira o conteúdo do bate-papo!"},
        ["game_disconnect"] = {"A conexão foi desconectada, faça login no jogo novamente!"},
        ["system_kicktout"] = {"O sistema foi expulso da sala, faça login novamente!"},
        ["account_already_login"] = {"A conta está logada em outro lugar!"},
        ["game_free_time"] = {"Seu tempo de jogo de experiência está cheio hoje, por favor, vá para recarregar, obrigado!"},
        ["game_info_null"] = {"Informações do jogo não encontradas!"},
        -- ["game_enter_score"] = {"transporte mínimo: %d"},
        ["game_waitting"] = {"Novos jogos disponíveis em breve, fique ligado"},
        ["game_not_open"] = {"O jogo ainda não está aberto!"},
        ["game_is_updating"] = {"Atualizando, aguarde"},
        ["game_update_in"] = {"Adicionado à fila de download"},
        ["game_install_success"] = {"Download e instalação concluídos"},
        ["game_install_failed"] = {"Falha na instalação, tente novamente mais tarde!"},
        ["socre_less_enter_game"] = {"A moeda do seu jogo é menor que %s, você não pode entrar no jogo!"},
        ["get_roominfo_null"] = {"Falha ao obter informações do quarto!"},
        ["exit_game_tip"] = {"Tem a certeza que deseja desistir deste jogo?"},
        ["game_tip_no_sub_item"] = {"Sem subitens!!!"},
        ["game_tip_no_money"] = {"Moedas insuficientes, por favor recarregue"},
        ["game_tip_no_function"] = {"Funcionalidade não disponível!"},
        ["bank_tips_1"] = {"Você não se juntou ao clube, não pode usar esta função"},
        ["bank_tips_2"] = {"Por favor, adicione o jogador para o qual você deseja transferir moedas"},
        ["bank_tips_3"] = {"Por favor, insira a quantidade de moedas para transferir"},
        ["bank_tips_4"] = {"Pelo menos 100 moedas de ouro a serem transferidas"},
        ["bank_tips_5"] = {"Você transferiu com sucesso %s moedas para %s"},
        ["bank_tips_6"] = {" Por favor, insira o ID do jogador correto"},
        ["game_tip_exit_room"] = {"Como você está apostando há muito tempo, foi solicitado que você saísse da sala, obrigado!"},
        ["game_tip_exit_room_1"] = {"Você já apostou, espere essa partida terminar para sair do jogo!"},
        ["game_tip_exit_room_2"] = {"Espere essa partida terminar para sair do jogo!"},
        ["game_tip_cannot_oper"] = {"Não é possível realizar operações nesta fase"},
        ["game_tip_cannot_oper_1"] = {"Você já apostou, não é possível alterar o multiplicador da aposta"},
        ["game_tip_not_bet"] = {"Você ainda não apostou,  não é possível auto-apostar"},  
        ["game_tip_not_bet1"] = {"Você ainda não apostou"},  
        ["game_tip_bet_fail"] = {"Por favor, insira o montante da aposta"},  
        ["game_enter_score"] = {"Insira o montante da aposta"},
        ["game_enter_rate"] = {"Insira o multiplicador de apostas"},
        ["game_carsh_bet"] = {"Apostas"},
        ["game_carsh_beted"] = {"Apostado"},
        ["game_carsh_wait"] = {"Por favor, espere..."},
        ["game_carsh_not_win"] = {"Oops !"},
        ["game_carsh_immewin"] = {"Ganhe Agora"},
        ["game_carsh_wined"] = {"Parabéns por ganhar"},
        ["game_prohibit_leave"] = {"No jogo, você não pode sair"},
        ["apk_version_error"] = {"Versão errada"},
        ["scrollView_default"] = {"Atualmente sem dados"},  
        ["sign_gold"] = {"Parabéns, você ganhou {%s} moedas"},
        ["get_room_info"] = {"Solicitando informações do quarto, aguarde"},
        ["crash_stop_failed"] = {"A paragem imediata falhou"},
        ["crash_not_need_stop"] = {"immediate not need stop"},
        ["club_tips_1"] = {"Entrou com sucesso"},
        ["club_tips_2"] = {"Solicitação enviada, aguarde a revisão do líder"},
        ["club_tips_3"] = {'Deseja expulsar "%s" do clube'},
        ["club_tips_4"] = {"Você foi expulso do clube"},
        ["club_tips_5"] = {"Insira o conteúdo do anúncio"},
        ["club_tips_6"] = {"Se deve se retirar do clube"},
        ["club_tips_7"] = {"A solicitação de entrada precisar ser revisada"},
        ["club_tips_8"] = {"Saia com sucesso"},

        ["game_no_bet_time"] = {"tempo sem aposta"},
        ["gamebanker_no_time"] = {"Tempo sem fim"},
        ["game_zhuang_no_bet"] = {"O banqueiro não pode fazer apostas"},
        ["game_select_money"] = {"Selecione um valor de aposta"},
        ["game_money_not_enough"] = {"Moedas de ouro insuficientes, não pode apostar"},
        ["game_bet_fail"] = {"Falha ao apostar %d moedas"},
        ["game_banker_score"] = {"As moedas de ouro são inferiores a %d e não podem ser negociadas"},
        ["game_apply_banker"] = {"A inscrição foi bem-sucedida, aguarde a próxima rodada!"},
        ["game_cancel_banker_fail"] = {"O jogo começou, não pode jogar!"},
        ["socre_less_kick_out"] = {"A moeda do seu jogo é inferior a %s, você não pode continuar o jogo"},
        ["kick_out_game"] = {"Após um longo período de operação, o sistema é expulso da sala"},
        ["exit_app"] = {"Tem certeza de que deseja sair do jogo?"},
        ["baseEnsure_1"] = {"金币低于%s,可领取"},
        ["score_less"] = {"Sua moeda de ouro é insuficiente, seja recarregada"},
        ["shop_threshold"] = {"É mais favorável comprar um pacote de presente. Quer ir para comprar?"},
        ["sign_tips_1"] = {"Ligue depois de vincular seu telefone ou armazenar valor!"},
        ["sign_tips_2"] = {"Função de desbloqueio após a recarga!"},
        ["score_less_2"] = {"A moeda do seu jogo é inferior a %s, você não pode continuar o jogo!"},
        ["VIP_less"] = {"Você precisa alcançar o nível VIP %d para poder entrar no jogo!"},
        ["tel_error_1"] = {"Formato incorreto do número do telefone celular"},
        ["tel_error_2"] = {"Erros da obtenção de um código de verificação"},
        ["input_tel"] = {"Digite o número do celular"},
        ["input_code"] = {"Digite o código de verificação"},
        ["cashout_tip"] = {"Por favor, verifique se as informações estão corretas. A auditoria será concluída em 5 minutos e o pagamento será efetuado em até 7 horas."},
        ["cashout_state1"] = {"Em revisão"},
        ["cashout_state2"] = {"Erro de pedido"},
        ["cashout_state3"] = {"concluído"},
        ["cashout_state4"] = {"Ordens inconformes"},
        ["cashout_example1"] = {"(Exemplo:8797***5566)"},
        ["cashout_example2"] = {"(Exemplo:8797******5566)"},
        ["cashout_example3"] = {"(Exemplo:5513*****5566)"},
        ["cashout_example4"] = {"(Exemplo:freeslot*@gmail.com)"},
        ["cashout_example5"] = {"(Exemplo:abc8797***55ss)"},
        ["cashout_tip2"] = {"Você ainda precisa de %s apostas."},--{"Apostas ainda falta da quantia de %s"},
        ["today"] = {"today"},
        ["day_before"] = {"%d day before"},
        ["truco_chat1"] = {"Eu não posso!"},
        ["truco_chat2"] = {"Você decide."},
        ["truco_chat3"] = {"Eu não tenho nada."},
        ["truco_chat4"] = {"OK"},
        ["truco_chat5"] = {"Graças a Deus."},
        ["truco_chat6"] = {"Uau!"},
        ["truco_chat7"] = {"Nós podemos ir!"},
        ["truco_chat8"] = {"Bom!"},
        ["truco_chat9"] = {"E aí?"},
        ["tips_wait_status"] = {"Por favor, espere que o estado do jogo se sincronize."},
        ["modify_face_success"] = {"salvo com sucesso"},
        ["shareLaxin_tips"] = {"Número insuficiente de convites válidos, você pode atender aos requisitos da seguinte forma"},
        ["vip_limit"] = {"É necessário alcançar o nível VIP1 para participar."},
    },
    ["zh"] = {
        ["network_delay"]= {"您的网络有点不给力"},
        ["network_timeout"]= {"你的网络连接有异常，请稍后再试"},
        ["operate_success"]={"操作成功！"},
        ["input_money"]= {"请输入数额"},
        ["input_error_money"]= {"数额输入有误"},
        ["user_score_less"]= {"身上携带金币不足！"},
        ["bank_score_less"]= {"银行金币不足！"},
        ["old_bankpsd_empty"]={"旧银行密码不能为空！"},
        ["old_bankpsd_error"]={"旧银行密码输入错误！"},
        ["new_bankpsd_empty"]={"新银行密码不能为空！"},
        ["two_bankpsd_notequal"]={"两次输入的密码不一致"},
        ["bankpsd_modify_success"]={"银行密码修改成功！"},
        ["bank_transfer_tips"]={"您目前无法使用此功能，详情请联系客服！"},
        ["input_psd_empty"]={"密码输入为空！"},
        ["psd_length_less6"]={"请输入至少6位字符"},
        ["bank_psd_error"]={"银行密码输入错误！"},
        ["input_id_empty"]={"请输入玩家ID"},
        ["input_id_error"]={"转账ID输入错误！"},
        ["input_money_empty"]={"转账金额不能为空！"},
        ["input_money_error"]={"请输入正确的转账金额！"},
        ["input_money_toobig"]={"转账金额超出当前银行金额！"},
        ["transfer_success"]={"转账成功！"},
        ["input_phone_empty"]={"请先输入手机号！"},
        ["copy_success"]={"复制成功！"},
        ["chat_content_empty"]={"请输入聊天内容！"},
        ["game_disconnect"] = {"连接已断开，请重新登录游戏!"},
        ["system_kicktout"] = {"被系统踢出房间，请重新登录！"},
        ["account_already_login"] = {"账号在其他地方登录！"},
        ["game_free_time"] = {"您今天的体验游戏时间已满，请前往充值，谢谢！"},
        ["game_info_null"] = {"游戏信息未能找到！"},
        -- ["game_enter_score"] = {"最低携带: %d！"},
        ["game_waitting"] = {"新游戏即将上线，敬请期待"},
        ["game_not_open"] = {"游戏暂末开启！"},
        ["game_is_updating"] = {"正在更新中，请稍后！"},
        ["game_update_in"] = {"已加入下载队列"},
        ["game_install_success"] = {"下载并安装完成"},
        ["game_install_failed"] = {"安装失败，请稍后再试!"},
        ["socre_less_enter_game"] = {"您的游戏币少于 %s,无法进入游戏！"},
        ["get_roominfo_null"] = {"获取房间信息失败！"},
        ["exit_game_tip"] = {"确定要退出游戏吗？"},
        ["game_tip_no_sub_item"] = {"没有子项目!!!"},
        ["game_tip_no_money"] = {"你的金币不足，请尽快补充"},
        ["game_tip_no_function"] = {"功能尚未开放!"},
        ["bank_tips_1"] = {"你还未加入俱乐部，无法使用该功能"},
        ["bank_tips_2"] = {"请添加要转让金币的玩家"},
        ["bank_tips_3"] = {"请输入转让金币数"},
        ["bank_tips_4"] = {"转让金币最少要超过100"},
        ["bank_tips_5"] = {"你已成功转让 %s 金币给 %s"},
        ["bank_tips_6"] = {" 请输入正确的玩家ID"},

        ["game_tip_exit_room"] = {"由于您长时间末投注，被请退出房间，谢谢！"},
        ["game_tip_exit_room_1"] = {"您已下注，请等待本局游戏结束再退出游戏！"},
        ["game_tip_exit_room_2"] = {"请等待本局游戏结束再退出游戏！"},
        ["game_tip_cannot_oper"] = {"现阶段无法进行操作"},
        ["game_tip_cannot_oper_1"] = {"你已投注，不能更换投注倍数"},
        ["game_tip_not_bet"] = {"你还没下注，不能自动投注"},
        ["game_tip_not_bet1"] = {"你还没下注"},
        ["game_tip_bet_fail"] = {"请输入投注金额"},
        ["game_enter_score"] = {"输入投注额"},
        ["game_enter_rate"] = {"输入投注倍数"},
        ["game_carsh_bet"] = {"投注"},
        ["game_carsh_beted"] = {"已经投注"},
        ["game_carsh_wait"] = {"请稍等..."},
        ["game_carsh_not_win"] = {"哎呀"}, --没有赢的叹气
        ["game_carsh_immewin"] = {"现在就赢"},
        ["game_carsh_wined"] = {"恭喜你赢得"},
        ["game_prohibit_leave"] = {"游戏中，不能离开"}, 
        ["apk_version_error"] = {"版本错误"},
        ["scrollView_default"] = {"目前没有数据"},
        ["sign_gold"] = {"恭喜你获得{%s}金币"},
        ["get_room_info"] = {"正在请求房间信息，请稍后"},
        ["crash_stop_failed"] = {"立享收益失败"},
        ["crash_not_need_stop"] = {"无须停止"},
        ["club_tips_1"] = {"加入成功"},
        ["club_tips_2"] = {"申请已提交，请等待会长审核"},
        ["club_tips_3"] = {'是否将 "%s" 踢出俱乐部'},
        ["club_tips_4"] = {"您已被踢出俱乐部"},
        ["club_tips_5"] = {"请输入公告内容"},
        ["club_tips_6"] = {"是否退出俱乐部"},
        ["club_tips_7"] = {"申请加入是否需要审核"},
        ["club_tips_8"] = {"退出成功"},

        ["game_no_bet_time"] = {"非下注时间"},
        ["gamebanker_no_time"] = {"非下庄时间"},
        ["game_zhuang_no_bet"] = {"庄家不能下注"},
        ["game_select_money"] = {"请选择下注金额"},
        ["game_money_not_enough"] = {"金币不足,不能押注"},
        ["game_bet_fail"] = {"下注 %d 金币失败"},
        ["game_banker_score"] = {"金币少于%d,不能上庄"},
        ["game_apply_banker"] = {"申请成功,请等待下一局!"},
        ["game_cancel_banker_fail"] = {"游戏已开始，不能下庄!"},
        ["socre_less_kick_out"] = {"您的游戏币少于 %s,无法继续游戏！"},
        ["kick_out_game"] = {"长时间末操作，被系统踢出房间！"},
        ["exit_app"] = {"您确定要退出游戏吗？"},
        ["baseEnsure_1"] = {"金币低于%s,可领取"},
        ["score_less"] = {"您的金币不足，是否充值"},
        ["score_less_2"] = {"您的游戏币少于 %s,无法继续游戏！是否充值？"},
        ["VIP_less"] = {"您需要达到VIP %d级别才能进入游戏!"},
        ["shop_threshold"] = {"购买礼包更优惠，是否前往？"},
        ["sign_tips_1"] = {"绑定手机后开启!"},
        ["sign_tips_2"] = {"储值后开启!"},
        ["tel_error_1"] = {"手机号码格式不正确"},
        ["tel_error_2"] = {"获取验证码异常"},
        ["input_tel"] = {"输入手机号"},
        ["input_code"] = {"输入验证码"},
        ["cashout_tip"] = {"我们会收取%s的提现服务费用，付款时间最快为5分钟到7小时内，请检查您的填写信息是否正确"},
        ["cashout_state1"] = {"审核中"},
        ["cashout_state2"] = {"订单错误"},
        ["cashout_state3"] = {"已完成"},
        ["cashout_state4"] = {"违规订单"},
        ["cashout_example1"] = {"(示例:8797***5566)"},
        ["cashout_example2"] = {"(示例:8797******5566)"},
        ["cashout_example3"] = {"(示例:5513*****5566)"},
        ["cashout_example4"] = {"(示例:freeslot*@gmail.com)"},
        ["cashout_example5"] = {"(示例:abc8797***55ss)"},
        ["cashout_tip2"] = {"投注额还差%s"},
        ["today"] = {"今天"},
        ["day_before"] = {"%d天前"},
        ["truco_chat1"] = {"truco_chat1"},
        ["truco_chat2"] = {"truco_chat2"},
        ["truco_chat3"] = {"truco_chat3"},
        ["truco_chat4"] = {"truco_chat4"},
        ["truco_chat5"] = {"truco_chat5"},
        ["truco_chat6"] = {"truco_chat6"},
        ["truco_chat7"] = {"truco_chat7"},
        ["truco_chat8"] = {"truco_chat8"},
        ["truco_chat9"] = {"truco_chat9"},
        ["tips_wait_status"] = {"请等待游戏状态同步。"},
        ["modify_face_success"] = {"修改头像或资料成功"},
        ["shareLaxin_tips"] = {"有效邀请人数不足，您可以通过以下方式达成条件"},
        ["vip_limit"] = {"达到vip3才可参与"},
    },
    ["EN"] = {
        ["network_delay"]= {"Your network is a little bit delayed"},
        ["network_timeout"]= {"Network error, please try again later"},
        ["operate_success"]={"Operation successful"},
        ["input_money"]= {"Enter your money first"},
        ["input_error_money"]= {"Money input error"},
        ["user_score_less"]= {"Not enough coins"},
        ["bank_score_less"]= {"Not enough coins in the bank"},
        ["old_bankpsd_empty"]={"Old bank password can't be empty"},
        ["old_bankpsd_error"]={"Old bank password entered incorrectly"},
        ["new_bankpsd_empty"]={"New bank password can't be empty"},
        ["two_bankpsd_notequal"]={"The passwords does not match"},
        ["bankpsd_modify_success"]={"Bank password modified with success!"},
        ["bank_transfer_tips"]={"You can't use this function currently, please contact customer service for "},
        ["input_psd_empty"]={"further information!"},
        ["psd_length_less6"]={"Enter at least 6 characters"},
        ["bank_psd_error"]={"Bank password entered incorrectly"},
        ["input_id_empty"]={"Please enter player ID"},
        ["input_id_error"]={"Incorrect transfer ID entry"},
        ["input_money_empty"]={"The transfer amount can't be empty"},
        ["input_money_error"]={"Enter the correct transfer amount"},
        ["input_money_toobig"]={"The transfer amount exceeds the current amount in the bank"},
        ["transfer_success"]={"Transfer success!"},
        ["input_phone_empty"]={"Please enter your phone number first"},
        ["copy_success"]={"Copied with success"},
        ["chat_content_empty"]={"Enter chat content"},
        ["game_disconnect"] = {"The connection was disconnected, please login to the game again!"},
        ["system_kicktout"] = {"The system was kicked out, please login again"},
        ["account_already_login"] = {"This account is already logged in in another place!"},
        ["game_free_time"] = {"Your today's free game time is full, please recharge to continue playing, thank you!"},
        ["game_info_null"] = {"Game info not found"},
        -- ["game_enter_score"] = {"最低携带: %d！"},
        ["game_waitting"] = {"New games available soon, stay tuned!"},
        ["game_not_open"] = {"The game is not open yet"},
        ["game_is_updating"] = {"Updating, please wait"},
        ["game_update_in"] = {"Added to download list"},
        ["game_install_success"] = {"Download and installation successful"},
        ["game_install_failed"] = {"Installation failed, please try again later!!"},
        ["socre_less_enter_game"] = {"Your remaining game coin is less than %s, you can't join the game"},
        ["get_roominfo_null"] = {"Failed to get room info"},
        ["exit_game_tip"] = {"Are you sure to exit this game?"},
        ["game_tip_no_sub_item"] = {"No subitems!!!"},
        ["game_tip_no_money"] = {"Insufficient coins, please recharge"},
        ["game_tip_no_function"] = {"Function not available!"},
        ["bank_tips_1"] = {"You are not part of the club, you can't use this function"},
        ["bank_tips_2"] = {"Please add the player you want to transfer coins to"},
        ["bank_tips_3"] = {"Please enter the amount of coins to transfer"},
        ["bank_tips_4"] = {"The miminum amount of coins to transfer is 100"},
        ["bank_tips_5"] = {"You have successfully transferred %s coins to %s"},
        ["bank_tips_6"] = {" Please enter the correct player ID"},

        ["game_tip_exit_room"] = {"As you have been betting for a long time, you have been asked to leave the room, thank you!"},
        ["game_tip_exit_room_1"] = {"You have already bet, wait for this match to end to leave the game!"},
        ["game_tip_exit_room_2"] = {"Wait for this match to end to exit the game!"},
        ["game_tip_cannot_oper"] = {"Unable to perform actions at the moment"},
        ["game_tip_cannot_oper_1"] = {"You have already bet, it is not possible to change the bet multiplier"},
        ["game_tip_not_bet"] = {"You haven't bet yet, it is not possible to autobet"},
        ["game_tip_not_bet1"] = {"You haven't bet yet"},
        ["game_tip_bet_fail"] = {"Please enter the bet amount"},
        ["game_enter_score"] = {"Enter the bet amount"},
        ["game_enter_rate"] = {"Enter the bet multiplier"},
        ["game_carsh_bet"] = {"Bets"},
        ["game_carsh_beted"] = {"Bet"},
        ["game_carsh_wait"] = {"Please wait..."},
        ["game_carsh_not_win"] = {"Oops!"}, --没有赢的叹气
        ["game_carsh_immewin"] = {"Win now"},
        ["game_carsh_wined"] = {"Congratulations for winning!"},
        ["game_prohibit_leave"] = {"You can't leave while in a game"}, 
        ["apk_version_error"] = {"Wrong version"},
        ["scrollView_default"] = {"Currently no data"},
        ["sign_gold"] = {"Congratulations, you've earned {%s} coins!"},
        ["get_room_info"] = {"Obtaining room info, please wait"},
        ["crash_stop_failed"] = {"Crash stop failed"},
        ["crash_not_need_stop"] = {"Crash stop not needed"},
        ["club_tips_1"] = {"Successfully joined"},
        ["club_tips_2"] = {"Request sent, waiting for leader's approval"},
        ["club_tips_3"] = {'Do you want to kick "%s" out of the club'},
        ["club_tips_4"] = {"You was kicked from the club"},
        ["club_tips_5"] = {"Enter the ad content"},
        ["club_tips_6"] = {"Do you want to quit the club"},
        ["club_tips_7"] = {"Joining request needs to be approved"},
        ["club_tips_8"] = {"Successfully quit"},

        ["game_no_bet_time"] = {"No bet time"},
        ["gamebanker_no_time"] = {"Unlimited time"},
        ["game_zhuang_no_bet"] = {"The dealer can't make bets"},
        ["game_select_money"] = {"Select bet amount"},
        ["game_money_not_enough"] = {"Not enough coins, unable to bet"},
        ["game_bet_fail"] = {"Failed to bet %d coins"},
        ["game_banker_score"] = {"Coins are less than %d and cannot be traded"},
        ["game_apply_banker"] = {"Successfully applied, wait for next round"},
        ["game_cancel_banker_fail"] = {"The game started, unable to play"},
        ["socre_less_kick_out"] = {"Your game coins is less than %s, you can't continue playing"},
        ["kick_out_game"] = {"After a long period of operation, the system is kicked out from the room"},
        ["exit_app"] = {"Are you sure to exit the game?"},
        ["baseEnsure_1"] = {"金币低于%s,可领取"},
        ["score_less"] = {"Insufficient coins, please recharge"},
        ["score_less_2"] = {"Your game coins is less than %s, you can't continue playing"},
        ["VIP_less"] = {"You need to reach VIP level %d to be able to join the game!"},
        ["shop_threshold"] = {"It's worthy to buy a gift package. Want to go to buy it?"},
        ["sign_tips_1"] = {"Turn on after binding your phone or depositing money!"},
        ["sign_tips_2"] = {"Unlock function after recharging!"},
        ["tel_error_1"] = {"Incorrect mobile phone number format"},
        ["tel_error_2"] = {"Error getting verification code"},
        ["input_tel"] = {"Enter mobile phone number"},
        ["input_code"] = {"Enter verification code"},
        ["cashout_tip"] = {"Please verify if all information is correct. The audit will be completed in 5 minutes and the payment will be made within 7 hours."},
        ["cashout_state1"] = {"In revision"},
        ["cashout_state2"] = {"Order error"},
        ["cashout_state3"] = {"Concluded"},
        ["cashout_state4"] = {"Nonconforming orders"},
        ["cashout_example1"] = {"(示例:8797***5566)"},
        ["cashout_example2"] = {"(示例:8797******5566)"},
        ["cashout_example3"] = {"(示例:5513*****5566)"},
        ["cashout_example4"] = {"(示例:freeslot*@gmail.com)"},
        ["cashout_example5"] = {"(示例:abc8797***55ss)"},
        ["cashout_tip2"] = {"Still need the bet amount of %s"},
        ["today"] = {"Today"},
        ["day_before"] = {"%d day before"},
        ["truco_chat1"] = {"I can't!"},
        ["truco_chat2"] = {"You are in charge"},
        ["truco_chat3"] = {"I don't have anything"},
        ["truco_chat4"] = {"OK"},
        ["truco_chat5"] = {"Thanks God"},
        ["truco_chat6"] = {"Wow!"},
        ["truco_chat7"] = {"Here we go!"},
        ["truco_chat8"] = {"Yes!"},
        ["truco_chat9"] = {"What's up?"},
        ["tips_wait_status"] = {"Please wait for the game state to sync."},
        ["modify_face_success"] = {"Successfully saved"},
        ["vip_limit"] = {"Only participants who have reached VIP3 can take part."},
    }
}
--服务器返回
languageConfig.serverMsgConfig = {
    ["bx"] = {
        [0]   = {"Operação realizada"},
        [94]  = {"Este comportamento não é possível no jogo"},
        [95]  = {"Limitar incompatibilidade de máquina"},
        [96]  = {"Entrada "},
        [97]  = {"O URL do Avatar está vazio"},
        [98]  = {"String contém string limitada"},
        [99]  = {"Parâmetros incorretos"},
        [100] = {"A conta não existe"},
        [101] = {"A conta foi banida"},
        [102] = {"Senha do banco incorreta"},
        [103] = {"Senha dinâmica incorreta"},
        [104] = {"Anomalia interna"},
        [105] = {"A conta usou a função de fechamento seguro"},
        [106] = {"Verifique se a terceira anormalidade de informações de login"},
        [107] = {"plataforma errada"},
        [108] = {"Falha na verificação de informações de login da terceira parte"},
        [109] = {"Useruin está incorreto"},
        [110] = {"Login o endereço IP está incorreto"},
        [111] = {"Permissões ocasculares"},
        [112] = {"Erro de senha de login"},
        [114] = {"Erro da lista de produtos"},
        [115] = {"O item não existe ou o item foi desabilitado"},
        [116] = {"O item atual não pode ser comprado"},
        [117] = {"O endereço de pagamento não está configurado"},
        [600] = {"mail error"},
        [601] = {"mail error"},
        [602] = {"mail error"},
        [603] = {"mail error"},
        [604] = {"mail error"},
        [700] = {"O montante da transferência é menor ou igual a zero"},
        [701] = {"O serviço seguro do sistema de jogo está temporariamente suspenso devido à manutenção do sistema"},
        [702] = {"Função de transferência desabilitada"},
        [703] = {"Endereço IP bloqueado pelo sistema, a transferência foi proibida"},
        [704] = {"A máquina atual está proibida de transferir dinheiro"},
        [705] = {"Não é possível transferir dinheiro para si mesmo"},
        [706] = {"Não é possível transferir a mesma quantidade de moedas de ouro para o mesmo usuário em 60 seg"},
        [707] = {"Não pertence ao mesmo clube"},
        [708] = {"Membros não podem transferir dinheiro entre si mesmos"},
        [709] = {"Não possui permissão para transferir"},
        [710] = {"Moedas de ouro insuficientes para transferência"},
        [711] = {"Como o personagem atual está no jogo, a transação não pode ser feita"},
        [720] = {"Esta máquina pode receber subsídios de falência que excedem o limite"},
        [721] = {"Eu posso receber o número de subsídios de falência que excede o limite"},
        [722] = {"A riqueza total é maior do que o limite para receber benefícios de falência"},
        [730] = {"O número de compartilhamento pessoal hoje foi recebido"},
        [731] = {"O número de compartilhamento de máquinas hoje foi recebido"},
        [732] = {"A função de compartilhamento foi fechada"},
        [800] = {"O clube já existe"},
        [801] = {"Falha na criação do clube"},
        [802] = {"Incompatibilidade do clube"},
        [803] = {"Clube não existe"},
        [804] = {"Já está no clube, não é possível entrar várias vezes"},
        [805] = {"O clube foi banido"},
        [806] = {"Não é o líder do clube"},
        [807] = {"Não é possível enviar vários múltiplos de adesão"},
        [808] = {"Não está no formulário de inscrição"},
        [809] = {"O criador não pode expulsar a si mesmo"},
        [810] = {"A outra parte já entrou em outro clube"},
        [811] = {"Não está no clube"},
        [812] = {"O criador não pode sair sozinho"},
        [900] = {"Tarefa não existe"},
        [911] = {"Recompensas de tarefas foram recebidas"},
        [912] = {"As recompensas da missão não podem ser coletadas"},
        [1004] = {"Código de verificação incorreto"},
        [1005] = {"Expiração do código de verificação"},
        [1006] = {"O número do celular já está em uso em outra conta"},
        [1007] = {"O prêmio foi reclamado"},
        [1008] = {"Código de verificação já usado"},
        [1009] = {"Não foi vinculado um número de telefone celular, não é possível receber a recompensa."},
        [1010] = {"Frequência de envio muito rápida."},
        [1300] = {"Este código não existe"},
        [1301] = {"Este código foi desativado"},
        [1302] = {"Não é possível ativar várias vezes o mesmo produto"},
        [1303] = {"Este código já foi usado"},
        [1304] = {"Este código foi expirado"},
        [1305] = {"O produto relativo ao código já foi retirado da loja"},
        [1306] = {"Atingiu o limite de usos do código"},
    },
    ["zh"] = {
        [0]   = {"操作成功"},
        [94]  = {"游戏中无法进行此行为"},
        [95]  = {"限制机器不匹配"},
        [96]  = {"登陆被禁止"},
        [97]  = {"头像URL为空"},
        [98]  = {"字符串含有限制字符串"},
        [99]  = {"错误的参数"},
        [100] = {"账号不存在"},
        [101] = {"账号被禁用"},
        [102] = {"银行密码错误"},
        [103] = {"动态密码错误"},
        [104] = {"内部异常"},
        [105] = {"帐号使用了安全关闭功能"},
        [106] = {"验证第三方登陆信息异常"},
        [107] = {"错误的平台ID"},
        [108] = {"第三方登陆信息验证失败"},
        [109] = {"UserUin不正确"},
        [110] = {"登陆IP地址不正确"},
        [111] = {"权限不正确"},
        [112] = {"登陆密码错误"},
        [114] = {"商品列表错误"},
        [115] = {"商品不存在或者该商品已被禁用"},
        [116] = {"当前商品不允许购买"},
        [117] = {"支付地址没有配置"},
        [600] = {"邮件错误"},
        [601] = {"邮件详情错误"},
        [602] = {"删除邮件错误"},
        [603] = {"领取奖励错误"},
        [604] = {"获取列表错误"},
        [700] = {"转帐的金额小于等于零"},
        [701] = {"由于系统维护，暂时停止游戏系统的保险柜服务"},
        [702] = {"转账功能被关闭"},
        [703] = {"IP地址被系统封禁,禁止转帐"},
        [704] = {"当前机器被禁止转帐"},
        [705] = {"无法自己给自己转账"},
        [706] = {"60秒内不能给相同用户转相同数量的金币"},
        [707] = {"不属于相同俱乐部"},
        [708] = {"会员之间无法相互转账"},
        [709] = {"没有权限转账"},
        [710] = {"转账金币不足"},
        [711] = {"因为当前角色在游戏中，无法进行交易"},
        [720] = {"本机器可领取破产补助次数超限"},
        [721] = {"本人可领取破产补助次数超限"},
        [722] = {"游戏币+银行金币一起大于可领取破产补助的门槛"},
        [730] = {"本日个人分享次数已经领完"},
        [731] = {"本日机器分享次数已经领完"},
        [732] = {"分享功能已经被关闭"},
        [800] = {"俱乐部已存在"},
        [801] = {"创建俱乐部失败"},
        [802] = {"俱乐部不匹配"},
        [803] = {"俱乐部不存在"},
        [804] = {"已经在俱乐部中，无法多次加入"},
        [805] = {"俱乐部已被禁用"},
        [806] = {"不是俱乐部部长"},
        [807] = {"无法多次提交加入申请"},
        [808] = {"不在申请表中"},
        [809] = {"创建者不能踢出自己"},
        [810] = {"对方已加入其他俱乐部"},
        [811] = {"不在俱乐部中"},
        [812] = {"创建者自己不能退出"},
        [900] = {"任务不存在"},
        [911] = {"任务奖励已经领取过了"},
        [912] = {"任务奖励无法领取"},
        [1004] = {"验证码不正确"},
        [1005] = {"验证码过期"},
        [1006] = {"该号码已经绑定"},
        [1007] = {"您以领取过奖励"},
        [1008] = {"验证码已经使用"},
        [1009] = {"未绑定手机，无法领取奖励"},
        [1010] = {"发送频率太快"},
        [1300] = {"邀请码不存在"},
        [1301] = {"邀请码已经被停用"},
        [1302] = {"相同礼包商品在未过期之内不能激活多个"},
        [1303] = {"邀请码已经使用过了"},
        [1304] = {"邀请码已经过期"},
        [1305] = {"邀请码所绑定的礼包商品已经下架"},
        [1306] = {"邀请码已达最大使用上限"},
    },
    ["EN"] = {
        [0]   = {"Operation done"},
        [94]  = {"This action is not possible in game"},
        [95]  = {"Limit device incompatibility"},
        [96]  = {"Entrance"},
        [97]  = {"Avatar URL is empty"},
        [98]  = {"String contains limited string"},
        [99]  = {"Wrong parameters"},
        [100] = {"The account doesn't exist"},
        [101] = {"The account was banned"},
        [102] = {"Wrong bank password"},
        [103] = {"Wrong dynamic password"},
        [104] = {"Internal anomaly"},
        [105] = {"The account used the secure close function"},
        [106] = {"Check the third-party login information abnormality"},
        [107] = {"Wrong platform ID"},
        [108] = {"Third-party login information verification failed"},
        [109] = {"Useruin is incorrect"},
        [110] = {"Wrong login IP address"},
        [111] = {"No permissions"},
        [112] = {"Login password error"},
        [114] = {"Product list error"},
        [115] = {"The item does not exist or was disabled"},
        [116] = {"This item can't be purchased"},
        [117] = {"The payment address is not set"},
        [600] = {"mail error"},
        [601] = {"mail error"},
        [602] = {"mail error"},
        [603] = {"mail error"},
        [604] = {"mail error"},
        [700] = {"The transfer amount is equal to or less than zero"},
        [701] = {"The game system's security is temporarily suspended due to system maintenance"},
        [702] = {"Transfer function disabled"},
        [703] = {"The IP address is blocked by system, transfer was prohibited"},
        [704] = {"The current device is prohibited from transferring money"},
        [705] = {"Unable to transfer money to yourself"},
        [706] = {"It is not possible to transfer the same amount of gold coins to the same user"},
        [707] = {"Does not belong to the same club"},
        [708] = {"Members can't transfer money between themselves"},
        [709] = {"No transfer permission"},
        [710] = {"No sufficient coins for transfer"},
        [711] = {"Since the current player is in a game, the transfer can't be made"},
        [720] = {"This device can receive bankruptcy subsidies that exceed the limit"},
        [721] = {"I can receive the bankruptcy subsidy amount that exceed the limit"},
        [722] = {"Total wealth is greater than the threshold for receiving bankruptcy bonus"},
        [730] = {"Today's personal share number received"},
        [731] = {"Today's device share number received"},
        [732] = {"The share function was disabled"},
        [800] = {"The club already exists"},
        [801] = {"Club creation failure"},
        [802] = {"Club incompatibility"},
        [803] = {"The club does not exist"},
        [804] = {"Already in the club, unable to enter multiple times"},
        [805] = {"The club was banned"},
        [806] = {"You are not club leader"},
        [807] = {"Unable to send multiple membership applications"},
        [808] = {"Not on the application form"},
        [809] = {"The creator can't kick itself"},
        [810] = {"The other party has already joined another club"},
        [811] = {"Not in the club"},
        [812] = {"The creator can't leave by itself"},
        [900] = {"The activity does not exist"},
        [911] = {"Activity rewards received"},
        [912] = {"The quest rewards can't be collected"},
        [1004] = {"Wrong verification code"},
        [1005] = {"The verification code has expired"},
        [1006] = {"The mobile number is already in use on another account"},
        [1007] = {"The prize has been claimed"},
        [1008] = {"Verification code already used"},
        [1009] = {"未绑定手机，无法领取奖励"},
        [1010] = {"发送频率太快"},
        [1300] = {"This code does not exist"},
        [1301] = {"This code has been disabled"},
        [1302] = {"It is not possible to activate the same product multiple times"},
        [1303] = {"This code has already been used"},
        [1304] = {"This code has expired"},
        [1305] = {"The product related to the code has already been withdrawn from the store"},
        [1306] = {"Reached the code usage limit"},
    }
};
function languageConfig:getString(strName,language)
    language = language or "bx" 
    if languageConfig[language] and languageConfig[language][strName] then
        print(languageConfig["zh"][strName][1])
        return languageConfig[language][strName][1]
    end
    return ""
end


for k,v in pairs(languageConfig.serverMsgConfig["zh"]) do
    -- print(v)
    languageConfig["zh"][k] = v
end

for k,v in pairs(languageConfig.serverMsgConfig["bx"]) do
    -- print(v)
    languageConfig["bx"][k] = v
end


return languageConfig
