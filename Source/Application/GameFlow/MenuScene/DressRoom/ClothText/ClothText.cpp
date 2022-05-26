#include "ClothText.h"
#include"../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/SaveData/SaveData.h"
namespace text {
	void ClothText::drawText(int chara_type, int outer_type, int under_type) {
		if (res::SaveData::save_data.chara_custom[chara_type].unlocked_outer_wear[outer_type])
			outerWearText(chara_type, outer_type);
		else unlockOuterText(outer_type);
		if (res::SaveData::save_data.chara_custom[chara_type].unlocked_under_wear[under_type])
			underWearText(under_type);
		else unlockUnderText(under_type);
	}
	void ClothText::unlockOuterText(int type) {
		if (type == 0)outerWearText(
			"解放条件:",
			"最初からあるよ。",
			"ってか、これ見てるあなたは開発者？",
			"",
			""
		);
		if (type == 1)outerWearText(
			"解放条件:",
			"庵子で5面をクリアする",
			"",
			"",
			""
		);
		if (type == 2)outerWearText(
			"解放条件:",
			"みさとで5面をクリアする",
			"",
			"",
			""
		);
		if (type == 3)outerWearText(
			"解放条件:",
			"アリスモード7面をクリアする",
			"",
			"",
			""
		);
		if (type == 4)outerWearText(
			"解放条件:",
			"ストーリーをクリアする",
			"",
			"",
			""
		);
		if (type == 5)outerWearText(
			"解放条件:",
			"エキストラをクリアする",
			"",
			"",
			""
		);
	}
	void ClothText::unlockUnderText(int type) {
		if (type == 0)underWearText(
			"解放条件:",
			"最初からある",
			"あぁ～バグ♪バグ♪",
			"",
			""
		);
		if (type == 1)underWearText(
			"解放条件:",
			"ステージ2を残機4以上でクリアする",
			"",
			"",
			""
		);
		if (type == 2)underWearText(
			"解放条件:",
			"アリスモードをレベル10以上で6面をクリアする",
			"",
			"",
			""
		);
		if (type == 3)underWearText(
			"解放条件:",
			"ノーマル以上をクリアする",
			"",
			"",
			""
		);
		if (type == 4)underWearText(
			"解放条件:",
			"アリスモードのレベル50以上で6面をクリアする",
			"",
			"",
			""
		);
		if (type == 5)underWearText(
			"解放条件:",
			"どのステージでも良いので",
			"残機0の状態でクリアする",
			"(練習モードは除く)",
			""
		);
	}
	void ClothText::outerWearText(int chara_type, int wear_type) {
		if (chara_type == 0) {//綾乃
			if (wear_type == 0)outerWearText(
				"綾乃が活動時に愛用している服。",
				"通っている学校で指定されている紺色で",
				"ブレザータイプの制服である。",
				"ちなみに、赤リボンは1年生らしい。",
				"機能: ホーミング鶴オプションが付く"
			);
			if (wear_type == 1)outerWearText(
				"涼しくて大人気(当社比)セーラー服!",
				"綿35％ ポリエステル65％という、",
				"着心地が良いセーラー服らしい。",
				"かわいい。",
				"機能: チャージオプションが付く"
			);
			if (wear_type == 2)outerWearText(
				"学校指定の制服シャツに",
				"上からセーターである。",
				"「みさと」と同じコーデにしてみたよ！",
				"かわいい！",
				"機能: 湾曲&レーザーオプションが付く"
			);
			if (wear_type == 3)outerWearText(
				"お恥ずかしながら・・・",
				"私が普段着ている部屋着だよ。",
				"え？雑かなぁ(汗)",
				"だって、制服以外わかんないんだもん！",
				"機能: オプションがランダムで付く"
			);
			if (wear_type == 4)outerWearText(
				"私の大親友とおそろ！",
				"シエナちゃんとの記憶が",
				"不思議と湧き上がってくる！",
				"また会えてうれしかったなぁ。",
				"機能: ホーミング鶴オプションが付く"
			);
			if (wear_type == 5)outerWearText(
				"学校指定のコートです。",
				"冬でも涼しい格好をしていたので、",
				"あんまり着た記憶がないなぁ。",
				"よく開放できたね。おめでとう",
				"機能: 広範囲コメットオプションが付く"
			);
		}
		if (chara_type == 1) {
			if (wear_type == 0)outerWearText(
				"みさとが通っている学校の制服です。",
				"高級感あふれる学校だったんでしょうか？",
				"それはともかく、彼女はかなり優秀",
				"なんだってさ。ホントかなぁ～？",
				"青春だねぇ～。・・・？"
			);
			if (wear_type == 1)outerWearText(
				"みさとように作られたセーラー服です。",
				"綿35％ ポリエステル65％だそうです。",
				"へぇ～、やるじゃん。",
				"ちなみに、みさとはセーラー服を着た",
				"事がないんだそうです。"
			);
			if (wear_type == 2)outerWearText(
				"キャラはこの服を持っていません。",
				"",
				"",
				"",
				""
			);
			if (wear_type == 3)outerWearText(
				"みさとの私服・・・？",
				"多分、自分のバンドの衣装",
				"だと思います。",
				"ってか、この子バンドやってたんだ",
				"ロックですねぇ～。"
			);
			if (wear_type == 4)outerWearText(
				"キャラはこの服を持っていません。",
				"",
				"",
				"",
				""
			);
			if (wear_type == 5)outerWearText(
				"キャラはこの服を持っていません。",
				"",
				"",
				"",
				""
			);
		}
		if (chara_type == 2) {
			if (wear_type == 0)outerWearText(
				"赤城が学校で来ていたと思われる制服。",
				"小柄なもんだから、高校時代の制服が",
				"切れるってことなんだろうか？",
				"君、大学生くらいだよね？",
				"まぁいっか。似合うし。"
			);
			if (wear_type == 1)outerWearText(
				"キャラはこの服を持っていません。",
				"",
				"",
				"",
				""
			);
			if (wear_type == 2)outerWearText(
				"キャラはこの服を持っていません。",
				"",
				"",
				"",
				""
			);
			if (wear_type == 3)outerWearText(
				"赤城の私服です。",
				"特に何も考えずに外に出るときは",
				"ジャージにパーカーって感じです。",
				"服に気を使ってないラフな感じ・・・。",
				"ハッハ!ワカルゥ～!(誰？)"
			);
			if (wear_type == 4)outerWearText(
				"赤ずきんみたいですね。",
				"えぇ、それだけですよ？",
				"特に深い意味はありません。",
				"ただ、親近感がわくでしょうね。",
				"ドッペルゲンガーだったら怖い。"
			);
			if (wear_type == 5)outerWearText(
				"キャラはこの服を持っていません。",
				"",
				"",
				"",
				""
			);
		}
		if (chara_type == 3) {
			if (wear_type == 0)outerWearText(
				"媛が活動時のみ愛用している服。",
				"上着は学校の制服ではないらしいが、",
				"セーラー服のような外見をしている。",
				"とある活動の衣装だったんだとか。",
				"機能: 通常オプション"
			);
			if (wear_type == 1)outerWearText(
				"キャラはこの服を持っていません。",
				"",
				"",
				"",
				""
			);
			if (wear_type == 2)outerWearText(
				"赤城と同じ制服です。",
				"暑くて嫌だからブレザーより",
				"セーターを着ているらしい。",
				"学校ではブレザーを腰に縛っている。",
				"機能: 通常オプション"
			);
			if (wear_type == 3)outerWearText(
				"あまり着こなさないラフな私服。",
				"暑がりなので年中薄着・・・",
				"ではないようです。さすがに。",
				"ちなみに、部屋でもこんな感じ。",
				"機能: 通常オプション"
			);
			if (wear_type == 4)outerWearText(
				"キャラはこの服を持っていません。",
				"",
				"",
				"",
				""
			);
			if (wear_type == 5)outerWearText(
				"キャラはこの服を持っていません。",
				"",
				"",
				"",
				""
			);
		}
		if (chara_type == 4) {
			if (wear_type == 0)outerWearText(
				"菴狐の標準セーラー服です。",
				"別にこのコ、学生じゃないよね？",
				"ということはコスプレ用の",
				"カンタンなセーラー服です。",
				"機能: 通常オプション"
			);
			if (wear_type == 1)outerWearText(
				"キャラはこの服を持っていません。",
				"",
				"",
				"",
				""
			);
			if (wear_type == 2)outerWearText(
				"キャラはこの服を持っていません。",
				"",
				"",
				"",
				""
			);
			if (wear_type == 3)outerWearText(
				"私服です。",
				"探偵チックな服が好きなんだとか。",
				"ところで、これも仮の姿",
				"なんでしょうか？",
				"機能: 通常オプション"
			);
			if (wear_type == 4)outerWearText(
				"キャラはこの服を持っていません。",
				"",
				"",
				"",
				""
			);
			if (wear_type == 5)outerWearText(
				"鞄には、メイク道具やら",
				"お菓子が備わっています。",
				"ロングコートを着たところで",
				"大きな尻尾は隠せない。",
				"機能: 通常オプション"
			);
		}
	}
	void ClothText::underWearText(int type) {
		if (type == 0)underWearText(
			"24枚車ひだのプリーツスカート。",
			"一般的な無地のウール50%ポリエステル50%です。",
			"とても触り心地が良いらしい。",
			"かわいい(かわいい)",
			"機能: 特になし。"
		);
		if (type == 1)underWearText(
			"24枚車ひだのプリーツスカート(ライン付き)。",
			"歩くたびにふわっと揺れる",
			"プリーツスカートは女の子らしさたっぷり。",
			"軽すぎて激しく動くとめくれちゃう！(きゃっ)",
			"機能: 敵から落ちるパワーアイテムが増す。"
		);
		if (type == 2)underWearText(
			"いわゆる清楚系のプリーツスカート。",
			"こういうのって、ひるがえして走りたくなるんだよねぇ。",
			"←ちょっと膝辺りがくすぐったいらしい。",
			"機能: 弾幕のボーナスを獲得する際に",
			"残機の欠片を1個落とす事がある。"
		);
		if (type == 3)underWearText(
			"学校の体操着(短パン)です。",
			"控えめに言って短パンは動きやすい。",
			"スポーツ万能な「みさと」と書いたタグがある。",
			"機能: 当たり判定がちょっとだけ小さくなる。",
			""
		);
		if (type == 4)underWearText(
			"赤いボックススカートです。",
			"アリスモードをある程度やりこんだ証。", //アリスモードをやりこんだ証
			"アリスモードの高難易度レベルなど",
			"が乗り越えられるような機能がついている。",
			"機能: Powerを350より下回らなくなる。"
		);
		if (type == 5)underWearText(
			"製作者がよく見る萎えるタイプのスカート",
			"制服のプリーツは履く人から見て左巻きが普通だ。",
			"つまり、この車ひだスカートの作りは間違っている。",
			"機能: キャンプを設置することはできないし、",
			"ボムを使うとリンゴゲージがマックスになる"
		);
	}
	void ClothText::outerWearText(
		const char* msg0,
		const char* msg1,
		const char* msg2,
		const char* msg3,
		const char* msg4
	) {
		int pos_x = 850;
		lib::StringDX::draw(pos_x, 425, msg0, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(pos_x, 475, msg1, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(pos_x, 525, msg2, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(pos_x, 575, msg3, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(pos_x, 625, msg4, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
	}
	void ClothText::underWearText(
		const char* msg0,
		const char* msg1,
		const char* msg2,
		const char* msg3,
		const char* msg4
	) {
		int pos_x = 850;
		lib::StringDX::draw(pos_x, 925, msg0, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(pos_x, 975, msg1, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(pos_x, 1025, msg2, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(pos_x, 1075, msg3, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(pos_x, 1125, msg4, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
	}
}