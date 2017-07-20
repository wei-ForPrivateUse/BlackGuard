/*
 * Replay(a2Game_Sample).h
 *
 *  Created on: Jan 14, 2015
 *      Author: wei
 */

#ifndef REPLAY_A2GAME_SAMPLE__H_
#define REPLAY_A2GAME_SAMPLE__H_

#include <iostream>
#include <fstream>

void Draw();

void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Color& color);
void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
void DrawString(int x, int y, const char *string, ...);
void DrawString(const b2Vec2& p, const char *string, ...);
void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);

class Replay_a2Game_Sample: public Test {
public:

	Replay_a2Game_Sample() {
		ANNWeights* weights = new ANNWeights({28, 20, 2}, {false, true, false}, {false, true, true}, true);

		double w[1022] = {-0.45755122020269623,0.8288511229008679,-1.0,0.28388854693432997,-0.28197273877045875,0.09670336645269545,1.0,-0.9241790857308222,0.2091260311410459,-0.2940302210618063,-1.0,0.41809227230569973,1.0,0.5523199941025762,0.21917959536842677,-0.32265034921402175,0.9050154954646892,0.8478307875247023,0.8514344679924096,0.5768078196571967,-0.10071107399164192,-0.14885716972621135,-0.09195736291561231,-0.11601740261214942,0.43730498514351174,0.14753110127943297,0.459853931257438,1.0,0.7609241140047678,0.11898848470990818,0.27674548652050185,-0.7055352567892286,0.7629123393631074,-0.15957288042709045,0.84608357781919,-0.909971911947748,0.8655422457976655,0.4298609707138755,0.6418394735458579,0.9082383653103916,-0.9015121433139385,-0.16574803483678097,-0.7104700162092826,-0.18324508643718107,-0.8958666182339259,-0.5932767462232911,0.6677508770660772,0.23224480767542194,-0.4999729783676753,0.2894351221530418,0.2652115468006617,-0.23532548496256844,-0.2484687903639627,0.6916286895866206,0.7428548782682813,-0.8403173095221315,-0.7242113154495027,0.08135121031871616,0.9204566311383299,0.7515111836596422,-0.19655032835872066,0.9687726724503676,-0.4066135100555873,-0.7398596205955937,0.49491333262808845,0.7054423323749257,-0.7799488964157593,-0.9020328449074849,0.11614902349230938,0.7149685939674186,-0.7389190457796543,-0.9728168306291195,0.6259784936145286,0.5905804270061161,0.7920516780371304,0.057531465112410994,-0.7434627222206518,-0.10384928988018337,0.924087059031122,-0.6738072882252064,0.6289042022471216,0.9223749028022815,-0.46371927838297033,-0.28232281766382683,-0.341239609132521,-0.40542407233238903,0.8752926380077587,0.6462631441780036,-0.5151428116935644,0.7279938821848645,0.8601074769854526,0.5332876332227314,0.607019125247792,0.2328967264686934,-0.19879101695271428,0.4310834503566435,0.32316341558473244,0.8416072874270153,-0.3748936770671397,-0.42903786616384043,-0.2596707181621025,0.3607206783161685,-0.5557454017614946,0.11255577806553298,0.24440867960049564,-0.43609028395067134,-0.20405833379921037,-0.10565189104879716,-0.06563758718600966,-0.9192596627142549,-0.9391551632848398,-0.5749514009613328,-0.17004018757322018,-0.946029398203458,0.46389068791803734,-0.5370502000982391,-0.918497019750139,0.4479632614543118,-0.9838100159454167,0.5557727728264791,-0.767005837681306,1.0,0.7403575309791729,0.5951330958260009,0.2850119946232945,-0.1145555438021249,0.020511859146772796,-0.24587482521190224,0.11221702102340445,0.43160469794102874,0.5943712542325388,-0.24523183336778473,-0.16695002683055157,0.4303338304474926,0.9617411785374135,0.5878089534519052,-0.9269208349838238,0.7080439493225859,-0.5589274919075843,-0.7094780019526956,-0.8921128670836312,0.2835978069769502,-0.3664593523824601,-0.7895058785930175,0.49016186247594795,-0.7260685181629882,0.873528316520212,0.15675093657662356,-0.7240439866947264,0.83788263152484,-0.08618234048332626,-1.0,-0.42765236952156815,-0.0027387360069530565,-0.5883960063872894,0.4133956182650642,-0.310080463869743,0.3070678466051918,0.42628951312513985,0.6513801187628622,-0.49296166677954667,-0.8507126875063566,0.3015864149512245,0.9605140940277118,0.29294577209458905,0.9351013261721454,0.5248954956327354,0.03619717210611351,0.45233441484274256,0.23763291957056612,-0.7845748289284249,-0.675844280379989,0.08453866917371675,-0.0985051177514263,0.10378982955690165,-0.8001675049987965,0.018580474935021282,0.07317197415441797,0.4622212615282128,-0.6967025022023038,0.8567923553766483,-0.43290045581045855,0.8046405218071876,-0.11431823908769413,0.7263384399740931,-0.2882880169919616,-0.49173264290311886,0.8874114014790797,-0.20837846162377605,-0.4545781760819554,0.7332076453369832,-0.21983193770304751,0.002282353710985889,0.7232158635630744,0.6506879951539245,0.8570037392421423,0.3386448651742456,-0.3949696625567986,-0.1497648987139465,0.492854250118822,-0.2821599769072697,-0.2642670818731833,0.7832034238652792,0.39287534853994555,-0.14608221435618146,-0.4548032219791872,-0.4924115183182306,-0.4880001277380065,0.030862563774227525,0.3548915039130758,0.3205807711879803,-0.7370352974469984,-0.40668378861688254,0.8691658620531053,-0.2349841201895138,0.02871947132689682,0.02714198322211326,0.6449007983974763,-0.48978854980804837,0.6208195221086701,0.7299175942541676,-0.10737918912549012,0.5212822846787867,-0.07967007930727923,0.41272986216028523,-0.6551411280958758,-0.7333299189506605,-0.4996833697955029,0.8611316731943806,0.4342577672614751,-0.7093550288696148,-0.15248111263448724,-0.21610208311033402,-0.3773012861476071,-0.31320335290489965,0.16511882190537291,-0.14618436658620795,-0.771530414370713,0.39962961091581384,-0.683968595023111,-0.3149291763018648,0.7892835327984058,0.31223336436964927,0.5775129618650559,-0.7853021843798301,-0.5232834006276166,0.7291880558600924,0.23676627911377807,0.6841842160330408,-0.33155367518540146,-0.5959316461662526,0.8481622329314676,-0.9759637576927106,0.3139305340960188,-0.8749019326311798,0.9698091648234617,-0.8704291437200817,0.6366195455344186,0.6315516396478063,-0.7536182088474837,0.6966205263621578,-0.9450181542689876,-0.7117289331731881,-0.48093118738677715,-0.3735242993284878,0.9217361076647341,0.9972420408552115,0.5892542194487882,0.3598222091114505,0.5200923988733117,-0.34668282725404065,-0.5694146269088245,-0.9948069247138676,0.30195616208287185,0.24620524564497623,-0.5573502930097542,0.1503332195969541,-0.07278896388805381,0.9441380445559486,-1.0,0.3731405909397385,0.8641902923292688,-0.6263907129495844,0.0030632222352406585,0.4404692020531268,-0.9505412940348745,0.5072498855568216,-0.9612194754151434,-0.36984178257755523,-0.43313442902672933,-0.7768341695928085,0.5173979696509368,-0.5899976636545466,-0.42835888804519046,-0.8146945679260844,0.26564404857391555,-0.8448262679226519,-0.5472700122638681,-0.7087845757256931,-0.9554732294674528,-0.8962476893652414,0.9599355806445858,0.7015345851762212,-0.9614478363510991,-0.48830778204700853,-0.12271491782831728,0.39751682939278565,-0.269727227768593,0.17486685417975636,-0.8391039075000211,0.12252646212246684,-0.5748642500705677,0.9119212249456844,-0.1850767136958539,-0.5605512898047118,0.6523717046010433,0.18142818875738143,0.9780898090021126,0.33173507865532426,-0.026813640176316697,0.8110183525250512,-0.8252683001840949,-0.8633151027338778,-0.06083706612734513,0.9186830609239552,-0.7466227000460398,-0.7779928613193957,-0.6746690894360701,0.9811084547417642,0.09319893515411899,-0.8554747721793524,-0.6374341504105984,0.047624080836999205,-0.9759649513577511,-0.8856562630511206,-0.8948481397266499,-0.9278161381033845,-0.8686502322236761,-0.7031700326805993,-0.8284519285611994,-0.24179040159142434,-0.25898193367816646,-0.00938044914071643,0.552480768931096,-0.522535612212421,0.7462281513796358,0.29975986427233453,0.3947380298824179,-0.7324992301652933,-0.6453812576981591,0.03414274045362023,0.19525286345633264,-0.09506399436143032,-0.6930580259766559,0.18359199794831849,0.41383854450936636,-0.4744756736337094,-0.9257395144154775,-0.13589767927147406,0.6255546507932069,0.25771528219052375,-0.19588587886023243,0.16911998086925994,-0.18900847775790397,0.8023854253076921,-0.37941620358444966,0.06880003943793313,0.6179400666770366,0.6814172799988084,0.19029340839067016,-0.37786524203628863,0.16107368433433836,0.4531536901552629,0.31299876564584306,0.08205535376706542,0.6973918095141437,0.06876489201915026,-0.49115608955021756,-0.5747840205826913,0.8327122047922003,0.5648797384329449,0.11825610035109481,0.5869860855410868,0.5269646597929977,-0.3226184745116864,0.619174592399492,-0.9819229392660592,-0.5026183058917276,0.1843067362871132,0.49600639502887306,-0.11931417429281559,0.700594520083527,-0.6384720283077641,-0.4022592917424572,-0.16959999777739998,0.6648219660310635,-0.277938886186819,-0.35063491059483365,0.7096776737894456,-0.9483516940211929,0.7503452637763891,-0.38412327784404404,0.994647702725446,0.8190265487341126,-0.0553913440380066,0.48672584900713617,-0.15503800576291676,-0.4269607467911521,-0.3493567620585765,-0.590583184756038,0.7441238861003044,0.5190571769788066,0.39874419217843804,-0.47833109242342875,0.1490751100251883,-0.3094869627496962,-0.25427841725239964,0.863758348139397,-0.10011871012303673,-0.6869589677868346,0.15094810689320806,-0.4460628499280103,0.6224907809122953,-0.7488616933913559,0.694474162460024,-0.18872218483509906,-0.30984694778368527,-0.21573433459779515,-0.22955907816316107,0.9035927878744919,0.9224037468544626,0.28058699626096345,0.8826614527601558,-0.1759034145506929,-0.03561736451879367,0.022738487754793636,0.05356027156674351,0.02770643294745445,-0.6583501938696724,-0.28352252384662724,0.22153081446540251,-0.7293337906107836,0.4582972943073904,-0.4253065702277844,0.9076850961887212,-0.2650674579478901,0.20741194922817738,0.9349481083420423,-0.10888993706025754,-0.22853166116286955,-0.8839644921153751,-0.38156361819433743,0.6434218975584283,0.3765189016113224,-0.5518224957159638,0.9044835789514887,-0.34226154652572033,-0.2670801932524449,-0.8558630841605416,0.01384854906436363,-0.2397553930103423,-0.34216557013872534,0.6778541299662193,0.7331231904357102,0.7755435190768737,-0.6685917075007293,0.6901632901432259,0.2855403619136395,0.12775535343584213,-0.44004686085718225,-0.5598376974700829,-0.6743135906730996,0.7669136004712027,-0.865241265228167,0.699951318475433,0.6810369359958038,0.7147794701628207,-0.12987271373456832,0.11445915383543308,0.1787925025076843,0.27391923561675857,-0.39692641998031897,-0.30921772363773425,-0.14175044599729722,0.4105658839027357,-0.6222319031146483,-0.671362423702995,-0.1900839211039893,-0.9176212237064053,-0.7206678655611595,-0.9360149048938676,-0.4061224615714621,0.54498459163503,0.46558536934037326,0.29790537265725453,0.3587577971714735,0.17988760019245748,0.10960112801202537,0.11852887304005866,0.510388507563815,-0.35754138943968816,-0.9368256579183831,-0.017939096945693747,0.62507337780918,0.8788255465176658,0.15919382160030168,-0.1940026739854008,0.15727972260157203,-0.5974424478846675,1.0,-0.6497608072858657,-0.7672466982318481,0.10916192299111327,0.3744945117079079,0.5177592348840733,0.1835260823258153,-0.2527042740930029,0.9806476782118214,0.059535481374208984,-0.4373333082053276,-1.0,0.08210491852122473,-0.11087047847284205,-0.9526124907774095,0.41321482479411054,0.5999313548302895,0.9893568457833811,0.03008315778175194,-0.9891019248319016,0.11823777605239136,-0.8848119359780822,-0.8905388067060522,0.867895048643819,0.37953560925652585,0.18826989042181358,0.7057645469694833,-0.09285068961380105,0.36971277903522215,0.5405600407562203,-1.0,-0.8253365599569289,0.1980372794097553,0.48491670668076464,0.18074486050195707,-0.8933509636284291,0.4431261426538008,0.9214291929806492,0.24679660670948964,-0.7071473455672134,-0.06508732447297529,0.8316475333769179,0.6525313566024988,-0.15384470263166278,0.8862027146861416,-0.46919021018021145,0.6230635590049717,0.6652802108775615,0.08222957181735759,0.8849737985681071,0.3272098441009563,-1.0,0.00442409399663581,0.5467400162696926,-0.2681838675974916,0.8539574368138525,0.29097538150504426,-0.3882674186296051,0.11772067607220213,0.024487686592818372,0.7142156802783046,-0.24070361142436533,0.31870370353589444,0.8015321048590345,-0.8105479618607888,0.7590752861393458,-0.3593155787941246,-0.9551222902809628,0.18702034798306102,-0.9591233434249161,0.7032367283220851,-0.27152433326771397,0.027199084244614116,0.02149937824171995,-0.5930611628083267,0.5835533565379543,0.8712968390156058,0.9636296505944204,-0.6402644758432827,0.29192402804320833,-0.7471379614897822,0.4517444690848902,-0.1898658655954388,0.9957207917739759,-0.22515143153871242,-0.322436067290897,0.4169478683867332,0.8845902984753639,-0.9947441398700627,0.9712182272842393,-0.9478174255637948,0.8242686816569638,0.9308701585179832,-0.7311503908998007,-0.8352362653871951,-0.0928048334968537,0.5578469601287999,-0.9881371483195067,-0.11207373465620896,0.7419386082937319,0.20733734370484336,-0.10719460906059641,-0.7888359862395663,-0.9738802695426864,-0.620981185735783,0.3774010498799184,0.1865650751948395,-0.39973066157906206,0.11123317471301745,0.7239368416819517,-0.34787940675622914,-0.8030556830034065,-0.6794094956392666,-0.040988970458647266,-0.5800879542512577,-0.8599478847389579,0.8898300082902694,-0.46057926237286395,0.6150095385665449,-0.2948353947901925,0.9904282274819776,-0.8332416460937213,-0.3935178983929014,0.5070684192280324,-0.0013537578492613354,-0.7953288914775779,-0.44046366405212667,-0.13741652492455184,-0.16113098206513538,0.9345709847625008,-0.8396588328552684,0.21680881511658903,-0.4174470825501612,-0.8255398831100872,-0.04912788089222052,-0.15695169710810858,-0.9624166528551829,0.6600869809698211,-0.5082132826704706,0.14717265690079337,-0.121414702869171,0.725912950362969,0.6558080795056407,0.4666713835914122,0.7009503402214242,-0.8304805361051107,0.8708338285666071,0.17893175884657284,0.5506896760199087,0.7363130257685427,-0.1866932404845724,0.9156574522818246,-0.676038655968366,0.32206859395828136,-0.4918328415748959,0.2189925714258284,0.5221934180292589,-0.12652602557835732,0.2892906063204635,0.7292348389064662,0.2218875277757062,0.19501961477028204,-0.3009595228791914,-0.9957388648337717,-1.0,-0.7024857163530662,0.27638721262726057,0.31509189623898665,0.4235774324976634,0.16084492475870985,-0.7851895913257667,0.4172042844509907,0.8661157542245173,-0.9255919160445609,0.293532475671973,0.16785614550712033,-0.06721009193403335,-0.8606759910367655,0.4764270872977765,0.14027327170298576,-0.9800990537029246,0.7061737573630276,0.6633617482590054,-0.4929059846111558,-0.7593702423682427,-0.5233171120613607,-0.6731336029541598,-0.377261079284492,0.037805490859934905,-0.7298383274518141,0.03392114545500427,-0.7780907998899887,-0.48217403642584644,0.9072962878870451,0.45630392818231336,-0.11053135185391316,-0.4321148591636042,-0.2770202058816871,-0.7789082661810031,0.9516505284750184,0.42205106540574266,0.13367864952485925,-0.7767471087641091,-0.3782554622745846,0.8547285312128179,0.342284802799402,0.16861598263634425,0.8508478373643004,0.5597244615084127,-0.18782789929098098,0.2873051659765417,0.17209071992290143,-0.3082448777476614,-0.8938481302897164,-0.14020440282593832,-0.7582466969843182,-0.82313748964475,-0.41362868788420076,-0.9392048178979558,-0.20967425020770133,-0.5852933492168757,0.19805723263004746,0.5989614030896542,-0.14266476224014213,0.19785053246266093,0.993330278470516,-0.9171707273025084,0.3625686860603602,-0.1853201891007747,-1.0,0.8736944488727182,0.8097554532077857,-0.34000727462974695,0.46997353486406207,0.20328050039363682,-0.9955543071347962,-0.3755601440526757,-0.17293532845929924,-0.835360969254117,-0.9767417269856149,0.6478214340451964,-0.9474790683409126,-0.5276258929402164,-0.753183050435057,0.5802679901325655,-0.6076384068644404,-0.2482209781444505,0.8407933344888895,-0.886729845222472,0.10340463129455027,-0.8013880029667838,-0.21782378113390988,0.7349932270317276,-0.177548031209655,0.6958465561448266,-0.41100684870916154,-0.49090857889625616,0.9649842040137089,-0.05034351075026862,-0.8891554594114676,0.06736160364277403,0.6556879954346215,0.569484430571177,0.43053304952167404,-0.8987373923574271,-0.22454447496689178,0.484327336306163,-0.4209736780780793,0.979866171543149,0.0933726100810433,0.5505179973288068,0.046351354582074754,0.6632554525023154,0.9666456271943754,-0.15313714157453776,-0.8644752947168288,0.36622516584292686,-0.04150197891696489,-0.9629193660289291,-0.9191127505370253,-0.9824554547882357,-0.8414867914290625,-0.21994467692556935,0.6875305514685275,0.6320796364503593,-0.6697349175234414,-0.11290190960252906,0.7012129439762395,-0.37296918147592956,-0.9745192950682732,-0.57816512595438,0.22127616617129742,0.8949683932677558,0.7925561081202913,0.8877469891147908,0.22169229582618083,-0.04269869119657527,0.8331937887326968,0.7959081124590212,-1.0,-0.518859449602443,-0.9526592158720811,0.7061553039820048,-0.35434752920881657,0.039064039503396805,0.9534767422023468,-0.5663547485395369,0.5551622136037697,0.8090258716378882,-0.7199019915631965,0.2918838339774981,0.6321365851990043,-0.14461876888110783,-0.2747878263178266,0.5641034504146473,0.10567109817692606,-0.32651781325892687,0.8545258434503841,1.4928730176132208E-5,0.27071338793103916,0.712842307539661,-0.2601607423974303,0.7509445279672166,0.09005560624311389,-0.36021001218475596,0.38138873956562264,-0.6236673570621354,-0.15634818705084086,0.4089366082535568,0.43894310293470706,0.582516860321836,-0.05745759276965264,-0.6525085939648566,-0.9379460415178114,0.9286546339698302,-0.6152116128605809,-0.20291020784083,-0.6951420077198047,-0.8923784465712825,-0.5484353357109957,0.7050598715989983,0.8345843938867483,0.2897763147444405,0.7371330107771532,-0.8350638770357308,-0.9366139556775198,0.38149985404169157,0.4285773203805238,-0.3770409907695891,-0.9857889882865887,0.42540768111897737,-0.45554959986972826,0.26396389377132007,0.033749938314738236,0.09734396816989233,-0.6044983889248698,-0.20081015766059768,0.5719704828345964,-0.37831814408681713,-0.7192391566828369,0.19468770943462613,-0.19517767357085394,0.9352589825871541,-0.7744082730829249,-0.8721633049205267,0.9387152306852642,0.06690793880250293,0.6750047745886943,0.3015758119033759,0.9206032470846609,0.9606745220419936,-0.2500660431748536,0.9352855895381349,0.5904299966925114,0.9203634776781021,-0.7999154014441486,-0.31210766995499484,-0.42608516567276356,0.48644503145675244,-0.9691698571549701,-0.45954180364279723,-0.9267316127637707,0.5528674645632979,0.5077617047778621,0.2440693815758836,-0.540446392752733,0.24005361647075465,0.5650951678048667,-0.700307965603164,-0.43304014073273,0.9171562109204647,-0.9953608664773226,-0.20147409641285177,0.2903333863289742,-0.8696250537807683,-0.2367656173705492,-0.9665140594132848,-0.20714670485022296,-0.902958996326431,-0.3902235579177915,-0.3884434366257453,0.34070552773989693,-0.08138767707574644,-0.928746877489041,-0.014696377741688693,-0.4077044268497125,-0.9700213950746913,0.3239415135667854,-0.806664590109089,0.14419703326923072,-0.0999819438515332,0.20338891621182978,0.7972775696570495,0.9409787903175654,0.5471302975604422,0.7150271434004131,-0.12432572534221557,0.7887953187351321,0.311840958322644,-0.7200270996206822,0.2536691539795302,0.298090839551427,0.9144208385362148,0.46997035471733084,0.1743173835299747,0.4443455886338742,0.8149629583528063,-0.5988397380676911,0.9057154785395145,0.9078107467282639,-0.19330421281157362,-0.12407533774109235,0.9956990355581729,-0.22217331377787003,-0.7510254554640804,0.3077466750832269,-0.34075296775425207,0.9466355871486876,0.8080339724694354,0.21990808430985523,-0.13646463121013236,0.7454300551753028,-0.2190330041292387,0.18827719707527663,0.4297176278899809,0.754529429375329,0.4754778150284494,-0.6993508605006432,-0.6188080901990051,-0.70775526231924,0.9113012979920273,-0.47482105764551896,-0.8037629053531834,0.600422281807681,-0.17328271661994676,0.7347911637573413,0.28292784608810995,0.8701283986114695,-0.9187679317541373,-0.9487333778533531,0.5987525079423072,0.5427593502267843,0.6580284818694282,0.7962601264964576,-0.050496392129674,0.8244095288851199,0.3666082125160187,0.9614218547190957,-0.9679951751795977,-0.6623280872702385,-0.6069527049761293,-0.7379472142721457,-0.19569714365803934,0.5000045114275586,-0.5785591705155702,0.1926073185716951,0.6003530360821314,0.5025390341844514,0.9318849700373038,-0.9303233075377453,0.21495250060628787,0.10515693521375254,0.4480211765444088,-0.4986251806748877,0.17566216178652108,0.2894355153505253,0.551136219345423,0.4656036818534057,-0.836879498231802,0.5825477513162239,-0.9647131728067582,0.2761786143239322,0.26376480966351223,-0.1626499766353418,0.37218504428784227,0.089009111656089,-0.2754154469882647,0.1818688237155988,-0.460011778479555,0.3377273200421157,0.04016801766966704,0.05547298603824244,0.1238731683455033,-0.05744565688851984,0.05579410365816315,0.2910096332899943,-0.4889550916897953,0.462036952749979,-0.0275829005213672,0.28792705055349926,0.42448027955349,-0.14878578667886563,-0.3523550629039224};

		weights->Set(w);
		m_scenemgr = new PScene(&m_scenemgr_conf, weights);

		m_monitor = new PMonitor(2);
		static_cast<PMonitor*>(m_monitor)->f(m_scenemgr);

	}

	void Step(Settings* settings) {
		Test::Step(settings);

		DrawNest(11.0f);
		Draw();

		std::cout<<m_stepCount<<" : <getgoodfood: "<<static_cast<PScene*>(m_scenemgr)->m_nest->GetGoodFoodsCollected()
				<<", getbadfood: "<<static_cast<PScene*>(m_scenemgr)->m_nest->GetBadFoodsCollected()<<">"<<std::endl;
		std::cout<<"Fitness: "<<static_cast<PMonitor*>(m_monitor)->GetFitness()<<std::endl;
	}

	void DrawNest(float a) {
		m_debugDraw.DrawSegment(b2Vec2(-a, -a), b2Vec2(-a, a),
				b2Color(0.8f, 0.8f, 0.8f));
		m_debugDraw.DrawSegment(b2Vec2(-a, a), b2Vec2(a, a),
				b2Color(0.8f, 0.8f, 0.8f));
		m_debugDraw.DrawSegment(b2Vec2(a, a), b2Vec2(a, -a),
				b2Color(0.8f, 0.8f, 0.8f));
		m_debugDraw.DrawSegment(b2Vec2(a, -a), b2Vec2(-a, -a),
				b2Color(0.8f, 0.8f, 0.8f));
	}

	static Test* Create() {
		return new Replay_a2Game_Sample;
	}

	void Draw() {
		b2Vec2 w_v[10];
		//walls
		w_v[3] = b2Vec2(-55, -55);
		w_v[2] = b2Vec2(-50, -55);
		w_v[1] = b2Vec2(-50, 55);
		w_v[0] = b2Vec2(-55, 55);
		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

		w_v[3] = b2Vec2(-55, -55);
		w_v[2] = b2Vec2(55, -55);
		w_v[1] = b2Vec2(55, -50);
		w_v[0] = b2Vec2(-55, -50);
		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

		w_v[3] = b2Vec2(55, -55);
		w_v[2] = b2Vec2(55, 55);
		w_v[1] = b2Vec2(50, 55);
		w_v[0] = b2Vec2(50, -55);
		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

		w_v[3] = b2Vec2(55, 55);
		w_v[2] = b2Vec2(-55, 55);
		w_v[1] = b2Vec2(-55, 50);
		w_v[0] = b2Vec2(55, 50);
		DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));

		//food area
		w_v[3] = b2Vec2(50, 50);
		w_v[2] = b2Vec2(-50, 50);
		w_v[1] = b2Vec2(-50, -50);
		w_v[0] = b2Vec2(50, -50);
		DrawSolidPolygon(w_v, 4, b2Color(0.7, 0.7, 0.7));

		//nest
		w_v[3] = b2Vec2(12, 12);
		w_v[2] = b2Vec2(-12, 12);
		w_v[1] = b2Vec2(-12, -12);
		w_v[0] = b2Vec2(12, -12);
		DrawSolidPolygon(w_v, 4, b2Color(0.5, 0.5, 0.5));

		//robots
		for(auto robot : static_cast<PScene*>(m_scenemgr)->GetNodesByTag(MAKE_TAG('r', 'o', 'b', 'o'))) {
			b2Body* bd1 = static_cast<PRobot*>(robot)->m_motor[0]->GetBody();
			w_v[0] = bd1->GetWorldPoint(b2Vec2(-0.25, -0.1));
			w_v[1] = bd1->GetWorldPoint(b2Vec2(0.25, -0.1));
			w_v[2] = bd1->GetWorldPoint(b2Vec2(0.25, 0.1));
			w_v[3] = bd1->GetWorldPoint(b2Vec2(-0.25, 0.1));
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));
			b2Body* bd2 = static_cast<PRobot*>(robot)->m_motor[1]->GetBody();
			w_v[0] = bd2->GetWorldPoint(b2Vec2(-0.25, -0.1));
			w_v[1] = bd2->GetWorldPoint(b2Vec2(0.25, -0.1));
			w_v[2] = bd2->GetWorldPoint(b2Vec2(0.25, 0.1));
			w_v[3] = bd2->GetWorldPoint(b2Vec2(-0.25, 0.1));
			DrawSolidPolygon(w_v, 4, b2Color(0.2, 0.2, 0.2));
			DrawSolidCircle(static_cast<PRobot*>(robot)->GetMainComponent()->GetPosition(), 0.5f, b2Color(0.9,0.5,0.4));
		}

		//obstacles
		for(auto obs : static_cast<PScene*>(m_scenemgr)->GetNodesByTag(MAKE_TAG('o', 'b', 's', 't'))) {
			DrawSolidCircle(static_cast<Block*>(obs)->GetPosition(), 4.0f, b2Color(0.3,0.3,0.35));
		}

		//foods
		for(auto food : static_cast<PScene*>(m_scenemgr)->GetNodesByTag(MAKE_TAG('f', 'o', 'o', 'd'))) {
			auto col = static_cast<Block*>(food)->GetBody()->GetFixtureList()->GetShape()->m_radius > 2.5 ? b2Color(0.2, 0.52, 0.3) : b2Color(0.8, 0.17, 0.17);
			DrawSolidCircle(static_cast<Block*>(food)->GetPosition(), static_cast<Block*>(food)->GetBody()->GetFixtureList()->GetShape()->m_radius, col);
		}
	}
};

void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
	const float32 k_segments = 16.0f;
	const float32 k_increment = 2.0f * b2_pi / k_segments;
	float32 theta = 0.0f;
	glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(color.r, color.g, color.b, 1);
	glBegin(GL_TRIANGLE_FAN);
	for (int32 i = 0; i < k_segments; ++i)
	{
		b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
		glVertex2f(v.x, v.y);
		theta += k_increment;
	}
	glEnd();
	glDisable(GL_BLEND);

	theta = 0.0f;
	glColor4f(color.r, color.g, color.b, 1);
	glBegin(GL_LINE_LOOP);
	for (int32 i = 0; i < k_segments; ++i)
	{
		b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
		glVertex2f(v.x, v.y);
		theta += k_increment;
	}
	glEnd();
}

void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(color.r, color.g, color.b, 1);
	glBegin(GL_TRIANGLE_FAN);
	for (int32 i = 0; i < vertexCount; ++i)
	{
		glVertex2f(vertices[i].x, vertices[i].y);
	}
	glEnd();
	glDisable(GL_BLEND);

	glColor4f(color.r, color.g, color.b, 1);
	glBegin(GL_LINE_LOOP);
	for (int32 i = 0; i < vertexCount; ++i)
	{
		glVertex2f(vertices[i].x, vertices[i].y);
	}
	glEnd();
}

void DrawString(int x, int y, const char *string, ...)
{
	char buffer[128];

	va_list arg;
	va_start(arg, string);
	vsprintf(buffer, string, arg);
	va_end(arg);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	gluOrtho2D(0, w, h, 0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(0.9f, 0.6f, 0.6f);
	glRasterPos2i(x, y);
	int32 length = (int32)strlen(buffer);
	for (int32 i = 0; i < length; ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, buffer[i]);
	}

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void DrawString(const b2Vec2& p, const char *string, ...)
{
	char buffer[128];

	va_list arg;
	va_start(arg, string);
	vsprintf(buffer, string, arg);
	va_end(arg);

	glColor3f(0.5f, 0.9f, 0.5f);
	glRasterPos2f(p.x, p.y);

	int32 length = (int32)strlen(buffer);
	for (int32 i = 0; i < length; ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, buffer[i]);
	}

	glPopMatrix();
}

void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_LINES);
	glVertex2f(p1.x, p1.y);
	glVertex2f(p2.x, p2.y);
	glEnd();
}

#endif /* REPLAY_A2GAME_SAMPLE__H_ */
