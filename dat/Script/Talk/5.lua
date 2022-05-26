dofile( './dat/Script/Library/Talker/Library.lua' )
--3面弾幕前の会話

function TalkScene()

AYANO = 0
HIME = 1
ALICE = 2
ID_MAX = ALICE

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(AYANO, 0, 250, 1000, 0.4)--キャラの立ち絵を追加
Chara.isBack(AYANO,true)
Chara.eye(AYANO, 1)
Chara.mouth(AYANO, 0)
Massage.setBoxL()
SimpleMassage(
name_("みさと"),
"まるで狂気の濃度なんて",
"無かったかのように優雅だね。",
""
)
Scene(1)
Chara.isBack(AYANO,false)
Chara.eye(AYANO, 1)
Chara.mouth(AYANO, 1)
SimpleMassage(
name_("綾乃"),
"確かに・・・。",
"",
""
)
Scene(2)
Chara.spawnFacial(AYANO, HAPPY, 0, 480)
SimpleMassage(
name_("綾乃"),
"確かに・・・。",
"ココで何か食べていく？",
""
)
Scene(3)
Chara.isBack(AYANO,true)
Chara.mouth(AYANO, 0)
Chara.spawn(HIME, 3, 400, 1070, 0.47)
Chara.eye(HIME, 1)
Chara.brow(HIME, 1)
Chara.mouth(HIME, 1)
SimpleMassage(
name_("媛"),
"私はパスで。",
"",
""
)
Scene(4)
Chara.spawnFacial(AYANO, STOP, 0, 0)
Chara.isBack(AYANO,true)
Chara.mouth(AYANO, 0)
Chara.spawn(HIME, 3, 400, 1070, 0.47)
Chara.eye(HIME, 1)
Chara.brow(HIME, 1)
Chara.mouth(HIME, 1)
SimpleMassage(
name_("媛"),
"私、パス...",
"こんな時間に食べたら太りそう",
"だから・・・。"
)
Scene(5)
Chara.isBack(HIME,true)
Chara.mouth(HIME, 0)
Massage.setBoxR()
SimpleMassage(
name_("???"),
"こんなところで何してるの？",
"",
""
)
Scene(6)
SummonBoss(N03_ALICE, 7)
WaitAndSkip(60)
Scene(7)
Chara.spawn(ALICE, 7, 1100, 1000, 0.4)--キャラの立ち絵を追加
Chara.eye(ALICE, 1)
Chara.mouth(ALICE, 1)
SimpleMassage(
name_("アリス・ショット・スカーレット..."),
"ダメだよ",
"狂限化してない純人間がここに",
"来ちゃ。"
)
Scene(8)
SimpleMassage(
name_("アリス・ショット(略)"),
"知らないの？",
"",
""
)
Scene(9)
SimpleMassage(
name_("アリス・ショット(略)"),
"知らないの？",
"狂気に感染したら80%死ぬんだよ。",
""
)
Scene(10)
Chara.isBack(ALICE,true)
Chara.isBack(HIME,false)
Chara.mouth(HIME, 1)
Chara.brow(HIME, 2)
Chara.mouth(ALICE, 0)
Massage.setBoxL()
SimpleMassage(
name_("媛"),
"え!?初耳だよ・・・",
"真丹羽ちゃん!？",
""
)
Scene(11)
Chara.isBack(HIME,true)
Chara.mouth(HIME, 0)
SimpleMassage(
name_("まにわ"),
"ふっふん♪",
"",
""
)
Scene(12)
SimpleMassage(
name_("まにわ"),
"ふっふん♪",
"知ってますとも！",
""
)
Scene(13)
SimpleMassage(
name_("まにわ"),
"ふっふん♪",
"知ってますとも！",
"その為の衣装とワクチンですから!"
)
Scene(14)
SimpleMassage(
name_("まにわ"),
"安心して突っ込んじゃって",
"ください！",
"ドヤァ"
)
Scene(15)
SimpleMassage(
name_("まにわ"),
"うわ、ちょーヤバイ♪",
"",
""
)
Scene(16)
Chara.isBack(HIME,false)
Chara.eye(HIME, 3)
Chara.brow(HIME, 1)
Chara.mouth(HIME, 1)
SimpleMassage(
name_("媛"),
"ふえぇぇ・・・?",
"むしろ不安になっちゃったよ(泣)",
""
)
Scene(17)
Chara.mouth(HIME, 0)
Chara.isBack(HIME,true)
SimpleMassage(
name_("まにわ"),
"あ、本当に大丈夫なんで。",
"ガチです。",
""
)
Scene(18)
Chara.eye(HIME, 1)
Chara.brow(HIME, 0)
Chara.brow(ALICE, 1)
Chara.mouth(ALICE, 1)
Chara.isBack(ALICE,false)
Massage.setBoxR()
SimpleMassage(
name_("アリス・ショット(略)"),
"もうしゃべってもいいかな？",
"",
""
)
Scene(19)
Chara.eye(ALICE, 2)
SimpleMassage(
name_("アリス・ショット(略)"),
"とは言え・・・",
"",
""
)
Scene(20)
SimpleMassage(
name_("アリス・ショット(略)"),
"とは言え・・・",
"こっちに来ちゃったから",
"追い返さなくちゃ"
)
Scene(21)
Chara.eye(ALICE, 1)
Chara.brow(ALICE, 2)
SimpleMassage(
name_("アリス・ショット(略)"),
"仕方ないよね。",
"でも手加減はしてあげるから。",
""
)
Scene(22)
PlayBGM(6)
WaitAndSkip(1)

end

--@EndScript