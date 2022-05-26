dofile( './dat/Script/Library/Talker/Library.lua' )
--6面弾幕後の会話

function TalkScene()

Scene(0)
Massage.reset()
WaitAndSkip(120)

Scene(1)
Massage.setBoxGray()
SimpleMassage(
name_(""),
"綾乃: シエナ！遊びに来たよ！",
"",
""
)

Scene(2)
SimpleMassage(
name_(""),
"綾乃: シエナ！遊びに来たよ！",
"シエナ: また家を荒らしに来たのね。",
""
)

Scene(3)
SimpleMassage(
name_(""),
"綾乃: シエナ！遊びに来たよ！",
"シエナ: また家を荒らしに来たのね。",
"綾乃: 今日は大丈夫！新しい弾幕を作ったから見てほしいの！"
)


Scene(4)
SimpleMassage(
name_(""),
"シエナ: 外でやって。",
"",
""
)

Scene(5)
SimpleMassage(
name_(""),
"シエナ: 外でやって。",
"綾乃: でもシエナ、外出れないじゃん。",
""
)

Scene(6)
SimpleMassage(
name_(""),
"シエナ: 外でやって。",
"綾乃: でもシエナ、外出れないじゃん。",
"シエナ: そうだけど・・・。"
)

Scene(7)
SimpleMassage(
name_(""),
"綾乃: でもシエナ、外出れないじゃん。",
"シエナ: そうだけど・・・。",
"綾乃: 今日のはすごいよ！綺麗なんだから！"
)

Scene(8)
SimpleMassage(
name_(""),
"数時間後・・・",
"",
""
)
WaitAndSkip(180)

Scene(9)
SimpleMassage(
name_(""),
"綾乃: あ、もうこんな時間だ。私帰るね。",
"",
""
)

Scene(10)
SimpleMassage(
name_(""),
"綾乃: あ、もうこんな時間だ。私帰るね。",
"シエナ: ・・・。",
""
)

Scene(11)
SimpleMassage(
name_(""),
"綾乃: あ、もうこんな時間だ。私帰るね。",
"シエナ: ・・・。",
"シエナ: さようなら。"
)

Scene(12)
SimpleMassage(
name_(""),
"シエナは、生まれつき体が弱く、",
"家から出たこともない少女だった。",
""
)

Scene(13)
SimpleMassage(
name_(""),
"だから学校も行けなくて",
"",
""
)

Scene(14)
SimpleMassage(
name_(""),
"たくさん友達も居なくて、",
"",
""
)

Scene(15)
SimpleMassage(
name_(""),
"ずっと寂しい思いをしていた。",
"",
""
)

Scene(16)
SimpleMassage(
name_(""),
"たった一人の友達との時間をのぞいて・・・。",
"",
""
)

Scene(17)
Massage.setColor(1,55,255,55)
SimpleMassage(
name_(""),
"End 1...「すべての始まり。」",
"",
""
)

Scene(18)
Massage.setColor(1,55,255,55)
Massage.setColor(2,255,255,255)
SimpleMassage(
name_(""),
"End 1...「すべての始まり。」",
"クリアおめでとう！",
""
)

Scene(19)
Massage.setColor(1,55,255,55)
Massage.setColor(2,255,255,255)
Massage.setColor(3,255,100,100)
SimpleMassage(
name_(""),
"End 1...「すべての始まり。」",
"クリアおめでとう！",
"次はエキストラやレベル10のAliceモードに挑んでみよう！"
)

end

--@EndScript