dofile( './dat/Script/Library/Talker/Library.lua' )
--Ex弾幕後の会話

function TalkScene()

AYANO=0
MISATO=1
AKAGI=2
HIME=3
IORIKO=4
KURO=5
ID_MAX = KURO

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(KURO, 12, 900, 900, 0.4)--キャラの立ち絵を追加
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("クロ"),
"愉しんだ。",
"",
""
)

Scene(1)
SimpleMassage(
name_("クロ"),
"愉しんだ。",
"この施設は好きにしてくれて",
"かまわない。"
)

Scene(2)
Chara.spawn(AKAGI, 2, 170, 1000, 0.4)--キャラの立ち絵を追加
Chara.img(tag(AKAGI), brow(1), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
SimpleMassage(
name_("赤城"),
"意外とあっさり。戦う必要あった？",
"",
""
)

Scene(3)
Chara.img(tag(AKAGI), brow(1), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("クロ"),
"シエナの用事も済んだ様子だし、",
"",
""
)

Scene(4)
Chara.img(tag(AKAGI), brow(1), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("クロ"),
"シエナの用事も済んだ様子だし、",
"私もこれだけ戦えば諦めも付くよ。",
""
)

Scene(5)
Chara.hide(AKAGI)
Chara.spawn(AYANO, 0, 300, 900, 0.32)--キャラの立ち絵を追加
Chara.img(tag(AYANO), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
SimpleMassage(
name_("綾乃"),
"いろいろ知ってるんだよね、",
"",
""
)

Scene(6)
SimpleMassage(
name_("綾乃"),
"いろいろ知ってるんだよね、",
"狂気とか詳しく説明してよ。",
""
)

Scene(7)
Chara.img(tag(AYANO), brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(2), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("クロ"),
"良いだろう。説明してやる。",
"",
""
)

Scene(8)
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
SimpleMassage(
name_("クロ"),
"我々、狂気勢はこの狂気の源",
"",
""
)

Scene(9)
SimpleMassage(
name_("クロ"),
"エナジーコアによってばら",
"撒かれた菌類で人身強化している。",
""
)

Scene(10)
SimpleMassage(
name_("クロ"),
"それだけでなく、この菌類が",
"「虚界脱獄計画」の手掛かりになる",
"可のう性も発見している。"
)


Scene(11)
Chara.hide(AYANO)
Chara.spawn(AKAGI, 2, 170, 1000, 0.4)--キャラの立ち絵を追加
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
SimpleMassage(
name_("赤城"),
"ようするに、元の生きていた世界に",
"帰るための研究で狂気ウィルスを",
"実験していたってわけ？"
)

Scene(12)
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("クロ"),
"あぁ、その通りだ。",
"もちろん、狂気と言われるほどの",
"物だとは思っていなかったがな。"
)

Scene(13)
SimpleMassage(
name_("クロ"),
"若くして身を危険にしている者達",
"を虚界に保護し、",
"安全な生活を送る。"
)

Scene(14)
SimpleMassage(
name_("クロ"),
"ココは、そういう場所らしい",
"",
""
)

Scene(15)
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
SimpleMassage(
name_("赤城"),
"へぇ、いい場所じゃん",
"",
""
)

Scene(16)
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(1), eye(2), mouth(3), back(false))
Massage.setBoxR()
SimpleMassage(
name_("クロ"),
"でも皆がそうでは無いんだ。",
"",
""
)

Scene(17)
Chara.img(tag(KURO), brow(1), eye(2), mouth(1), back(false))
SimpleMassage(
name_("クロ"),
"保護する必要が無いハズなのに、",
"",
""
)

Scene(18)
Chara.img(tag(KURO), brow(2), eye(1), mouth(1), back(false))
SimpleMassage(
name_("クロ"),
"保護する必要が無いハズなのに、",
"強引な理由を付けられて",
"運ばれて来た奴がいるんだ。"
)

Scene(19)
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
SimpleMassage(
name_("クロ"),
"狂気勢はそういう奴らの集まり・・・。",
"",
""
)

Scene(20)
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
SimpleMassage(
name_("赤城"),
"それは知らなかった・・・。",
"",
""
)

Scene(21)
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("クロ"),
"さて、君たちはこの狂気ウィルスが",
"元の世界と接触できるという事を",
"ご存じかな？"
)

Scene(22)
Chara.hide(AKAGI)
Chara.spawn(MISATO, 1, 300, 940, 0.36)--キャラの立ち絵を追加
Chara.img(tag(MISATO), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
SimpleMassage(
name_("みさと"),
"一通り資料を確認したけど、",
"そんな情報はなかったよ。",
""
)

Scene(23)
Chara.img(tag(MISATO), brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("クロ"),
"そうか。",
"",
""
)

Scene(24)
SimpleMassage(
name_("クロ"),
"そうか。",
"知っているのは",
"我々だけのようだな。"
)

Scene(25)
SimpleMassage(
name_("クロ"),
"私がこのエナジーコアを見つけた際",
"にはすでに影響を",
"受けていたから、"
)

Scene(26)
SimpleMassage(
name_("クロ"),
"細かく原因はわかっていないんだが",
"",
""
)

Scene(27)
SimpleMassage(
name_("クロ"),
"元の世界で起きた何かしらの",
"環境変化を受け元の世界と接触",
"できるようになったらしいんだ。"
)

Scene(28)
Chara.hide(MISATO)
Chara.spawn(AYANO, 0, 300, 900, 0.32)--キャラの立ち絵を追加
Chara.img(tag(AYANO), brow(1), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Chara.spawnFacial(AYANO, SWEAT, -100, 300)
Massage.setBoxL()
SimpleMassage(
name_("綾乃"),
"色々あったかもしれない・・・。",
"",
""
)

Scene(29)
Chara.img(tag(AYANO), brow(1), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Chara.spawnFacial(AYANO, STOP, -100, 600)
Massage.setBoxR()
SimpleMassage(
name_("クロ"),
"でも元の世界と接触できることに",
"確信を持ったのは、",
"シエナのワガママに付き合った時だ。"
)

Scene(30)
SimpleMassage(
name_("クロ"),
"一身上の都合って奴だ。",
"",
""
)

Scene(31)
SimpleMassage(
name_("クロ"),
"一身上の都合って奴だ。",
"ほかの奴だったら断ってたかもね。",
""
)

Scene(32)
Chara.hide(AYANO)
Chara.spawn(AKAGI, 2, 170, 1000, 0.4)--キャラの立ち絵を追加
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
SimpleMassage(
name_("赤城"),
"どんなワガママに付き合ったの？",
"",
""
)

Scene(33)
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("クロ"),
"たしか、",
"「もう一度だけ綾乃とお話ししたい」",
"だったな。"
)

Scene(34)
SimpleMassage(
name_("クロ"),
"深くは聞かなかったが。",
"",
""
)

Scene(35)
SimpleMassage(
name_("クロ"),
"やり方は割と単純で、",
"",
""
)

Scene(36)
SimpleMassage(
name_("クロ"),
"君ら、",
"数年前に降った不思議な",
"彗星を知っているか？"
)

Scene(37)
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
SimpleMassage(
name_("赤城"),
"あぁ、媛が狂わされた儀式の時だね。",
"",
""
)

Scene(38)
Chara.hide(AKAGI)
Chara.spawn(HIME, 3, 300, 930, 0.36)--キャラの立ち絵を追加
Chara.img(tag(HIME), brow(1), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
SimpleMassage(
name_("媛"),
"ちょっと赤城・・・!?",
"",
""
)

Scene(39)
Chara.img(tag(HIME), brow(1), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("クロ"),
"あの彗星は、",
"私が虚界から砕いて落とした",
"岩盤なんだ。"
)

Scene(40)
SimpleMassage(
name_("クロ"),
"狂気を含ませたら元の世界に落て、",
"本当に驚いたよ。",
""
)

Scene(41)
SimpleMassage(
name_("クロ"),
"あと、あの彗星には",
"手紙が中にあったはずだ。",
""
)

Scene(41)
Chara.hide(HIME)
Chara.spawn(AKAGI, 2, 170, 1000, 0.4)--キャラの立ち絵を追加
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Chara.spawnFacial(AKAGI, ACCENT, 100, 600)
Massage.setBoxL()
SimpleMassage(
name_("赤城"),
"あ！あれか！",
"",
""
)

Scene(42)
Chara.hide(AKAGI)
Chara.spawn(AYANO, 0, 300, 900, 0.32)--キャラの立ち絵を追加
Chara.img(tag(AYANO), brow(0), eye(1), mouth(1), back(false))
Chara.spawnFacial(AKAGI, STOP, 100, 600)
SimpleMassage(
name_("綾乃"),
"なんて書いてあったの",
"",
""
)

Scene(43)
Chara.hide(AYANO)
Chara.spawn(AKAGI, 2, 170, 1000, 0.4)--キャラの立ち絵を追加
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(1), back(false))
SimpleMassage(
name_("赤城"),
"「綾乃と狂気関連」の内容だったよ。",
"",
""
)

Scene(44)
Chara.hide(AKAGI)
Chara.spawn(MISATO, 1, 300, 940, 0.36)--キャラの立ち絵を追加
Chara.img(tag(MISATO), brow(1), eye(1), mouth(1), back(false))
SimpleMassage(
name_("みさと"),
"だから以前、",
"赤城は綾乃を探してたんだね。",
""
)

Scene(45)
Chara.hide(MISATO)
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("クロ"),
"まぁ、そういう訳だ。",
"",
""
)

Scene(46)
SimpleMassage(
name_("クロ"),
"ストレス発散に",
"付き合ってもらっちゃって",
""
)

Scene(47)
SimpleMassage(
name_("クロ"),
"ありがとな。",
"",
""
)

Scene(48)
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(false))
SimpleMassage(
name_("クロ"),
"次は、生きた場所で会おう",
"",
""
)

end

--@EndScript