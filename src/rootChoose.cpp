#include <Rcpp.h>
using namespace Rcpp;

static const double arr[] = {200, 1, 1.0034717485095, 1.00899904747889, 1.01601719086081, 1.02422625945998, 1.03344332019799, 1.04354733347196, 1.05445391258415, 1.06610214011913, 1.07844702108702, 1.09145485891825, 1.10510026949603, 1.1193641705837, 1.13423238109632, 1.14969461728005, 1.16574375605468, 1.18237528341472, 1.19958687422549, 1.21737806734668, 1.23575001124389, 1.25470526261037, 1.2742476254643, 1.29438202157771, 1.31511438546413, 1.33645157883806, 1.35840132067796, 1.38097212991681, 1.40417327844747, 1.42801475262775, 1.45250722184827, 1.47766201301665, 1.50349109003601, 1.53000703753204, 1.55722304822054, 1.58515291341808, 1.61381101628576, 1.64321232746702, 1.67337240283808, 1.7043073831359, 1.7360339952675, 1.76856955513562, 1.80193197184238, 1.83613975315426, 1.87121201213015, 1.90716847482957, 1.9440294890315, 1.9818160339049, 2.02054973058201, 2.0602528535932, 2.10094834312955, 2.14265981810499, 2.18541158999561, 2.22922867743786, 2.27413682157183, 2.32016250211918, 2.36733295418842, 2.4156761858034, 2.46522099615286, 2.51599699456193, 2.56803462018773, 2.62136516244392, 2.6760207821602, 2.7320345334847, 2.78944038653867, 2.84827325083416, 2.90856899946682, 2.97036449409732, 3.03369761073578, 3.09860726634507, 3.16513344627981, 3.23331723257901, 3.30320083313132, 3.37482761173294, 3.44824211905929, 3.5234901245724, 3.60061864938719, 3.67967600012066, 3.76071180374912, 3.84377704349939, 3.92892409580129, 4.01620676832928, 4.10568033916261, 4.19740159709401, 4.29142888311818, 4.38782213313252, 4.48664292188337, 4.58795450819241, 4.69182188149877, 4.79831180975384, 4.90749288870673, 5.0194355926196, 5.13421232645347, 5.2518974795662, 5.37256748096576, 5.49630085616325, 5.62317828567149, 5.75328266519641, 5.88669916756991, 6.02351530647448, 6.16382100201119, 6.30770864816449, 6.45527318221862, 6.60661215618247, 6.7618258102809, 6.92101714857302, 7.08429201675897, 7.25175918223931, 7.42353041649258, 7.59972057983882, 7.78044770865878, 7.96583310514071, 8.15600142962879, 8.35108079564938, 8.5512028676938, 8.7565029618384, 8.96712014928549, 9.18319736291083, 9.40488150690625, 9.63232356960852, 9.86567873960835, 10.1051065252362, 10.3507708775244, 10.6028403167487, 10.8614880626541, 11.1268921684748, 11.3992356588594, 11.6787066718182, 11.96549860481, 12.2598102650931, 12.5618460244645, 12.8718159785193, 13.1899361105632, 13.5164284603171, 13.8515212975551, 14.1954493008235, 14.5484537413906, 14.9107826725841, 15.2826911246755, 15.6644413054768, 16.0563028068198, 16.458552817093, 16.8714763400168, 17.2953664198425, 17.7305243731679, 18.1772600275656, 18.6358919672281, 19.1067477858397, 19.5901643468895, 20.0864880516503, 20.5960751150511, 21.1192918496793, 21.656514958157, 22.2081318341413, 22.7745408722075, 23.3561517868808, 23.9533859410919, 24.5666766843377, 25.19646970084, 25.8432233680006, 26.5074091254644, 27.1895118551062, 27.8900302722723, 28.6094773286141, 29.3483806268621, 30.107282847901, 30.8867421905144, 31.6873328241829, 32.5096453553267, 33.3542873074001, 34.2218836152537, 35.1130771341965, 36.0285291642001, 36.9689199897032, 37.9349494354874, 38.9273374391093, 39.9468246403901, 40.9941729884785, 42.0701663670184, 43.1756112379687, 44.3113373046413, 45.4781981945382, 46.6770721625881, 47.9088628154007, 49.1744998571766, 50.4749398579289, 51.8111670446935, 53.1841941164275, 54.5950630833134, 56.0448461312113, 57.5346465120235, 59.0655994607597, 60.6388731401138, 62.2556696133906, 63.9172258466451, 65.6248147409232, 67.3797461955217, 69.1833682032125, 71.0370679784051, 72.9422731192533, 74.9004528047388, 76.9131190278029, 78.9818278656237, 81.1081807881749, 83.293826006236, 85.5404598600579, 87.8498282499295, 90.2237281099254, 92.6640089261555, 95.1725743008801, 97.7513835638943, 100.402453432628, 103.127859722459, 105.92973910877, 108.810290942347, 111.771779119746, 114.816534010323, 117.94695444165, 121.165509745143, 124.474741863711, 127.877267523363, 131.375780470723, 134.973053778488, 138.671942220916, 142.475384721495, 146.386406875024, 150.408123546388, 154.543741548398, 158.79656240113, 163.169985175267, 167.667509422052, 172.292738192505, 177.049381148672, 181.941257769744, 186.972300655968, 192.146558933384, 197.468201762493, 202.941521954077, 208.570939695472, 214.361006390733, 220.316408618184, 226.441972209024, 232.7426664507, 239.223608418942, 245.890067442431, 252.747469704214, 259.801402984104, 267.057621546453, 274.522051177782, 282.200794378947, 290.100135716616, 298.226547339033, 306.586694661128, 315.1874422243, 324.035859736236, 333.139228296421, 342.505046813083, 352.141038617536, 362.055158282085, 372.255598647803, 382.750798068748, 393.549447879337, 404.660500091855, 416.093175331264, 427.856971014715, 439.961669783407, 452.417348194653, 465.234385682297, 478.423473793847, 491.995625712977, 505.962186076321, 520.334841093747, 535.125628981619, 550.346950718818, 566.011581135638, 582.132680345976, 598.723805533551, 615.79892310326, 633.372421209103, 651.459122670472, 670.074298289001, 689.233680578515, 708.953477921058, 729.250389162357, 750.141618660523, 771.644891802234, 793.778471001048, 816.561172193036, 840.012381845347, 864.152074493822, 889.000830826327, 914.57985632893, 940.911000512676, 968.01677673921, 995.92038266412, 1024.64572131745, 1054.21742284144, 1084.66086690627, 1116.00220582511, 1148.26838839056, 1181.48718445524, 1215.68721028003, 1250.89795467417, 1287.14980595219, 1324.47407973355, 1362.9030476115, 1402.46996671881, 1443.20911021852, 1485.15579874906, 1528.34643285394, 1572.8185264272, 1618.61074120657, 1665.76292234781, 1714.31613511421, 1764.31270271672, 1815.79624534109, 1868.81172039977, 1923.40546404725, 1979.62523399895, 2037.52025369514, 2097.14125785238, 2158.5405394467, 2221.77199817385, 2286.89119043359, 2353.95538088647, 2423.02359563301, 2494.15667706689, 2567.41734045541, 2642.87023230208, 2720.58199054809, 2800.62130667124, 2883.0589897426, 2967.96803250339, 3055.42367952628, 3145.5034975277, 3238.28744789951, 3333.85796153101, 3432.30001599405, 3533.70121516699, 3638.15187137486, 3745.74509012651, 3856.5768575313, 3970.74613048102, 4088.35492968545, 4209.5084356526, 4334.31508770784, 4462.88668614899, 4595.33849763782, 4731.78936393122, 4872.36181405907, 5017.18218005925, 5166.38071638325, 5320.09172309041, 5478.45367295177, 5641.60934258904, 5809.70594777776, 5982.89528304853, 6161.33386572366, 6345.18308453181, 6534.60935294759, 6729.78426740733, 6930.88477055801, 7138.09331970074, 7351.59806059549, 7571.59300679982, 7798.2782247187, 8031.8600245497, 8272.55115731274, 8520.57101816013, 8776.14585616886, 9039.50899082405, 9310.90103540858, 9590.57012752138, 9878.77216695401, 10175.7710611624, 10481.8389785788, 10797.256610016, 11122.3134384255, 11457.3080172788, 11802.5482578487, 12158.3517256804, 12525.0459465461, 12902.9687221909, 13292.4684561865, 13693.904490217, 14107.647451137, 14534.0796091465, 14973.5952474453, 15426.6010437355, 15893.5164639569, 16374.7741686499, 16870.8204323552, 17382.1155764716, 17909.1344160088, 18452.3667206825, 19012.3176908203, 19589.5084485541, 20184.4765447973, 20797.7764825169, 21429.9802568296, 22081.6779124669, 22753.4781191733, 23446.0087656184, 24159.9175724252, 24895.8727249341, 25654.5635263428, 26436.7010718868, 27243.0189447395, 28074.2739343425, 28931.2467778916, 29814.7429257325, 30725.5933314445, 31664.6552674138, 32632.8131667272, 33630.9794922411, 34660.0956337117, 35721.1328339003, 36815.0931445952, 37943.0104135274, 39105.9513031853, 40305.0163425678, 41541.3410129508, 42816.096868774, 44130.4926947972, 45485.7757007045, 46883.2327543825, 48324.1916551321, 49810.0224481196, 51342.138781412, 52921.9993069884, 54551.1091271643, 56231.0212879115, 57963.3383206091, 59749.7138338062, 61591.8541566322, 63491.5200355471, 65450.5283861723, 67470.7541020074, 69554.1319218957, 71702.6583581582, 73918.3936873871, 76203.4640059488, 78560.0633523169, 80990.4558984253, 83496.9782123054, 86082.0415943425, 88748.1344895646, 91497.8249784643, 94333.7633489202, 97258.6847518885, 100275.411943609, 103386.858117171, 106596.029826365, 109906.030004861, 113320.061083845, 116841.428211337, 120473.542576552, 124219.92484274, 128084.208692082, 132070.144486329, 136181.603046988, 140422.579558985, 144797.197601881, 149309.713312835, 153964.519685643, 158766.151010353, 163719.287458072, 168828.759815764, 174099.554375966, 179536.817986542, 185145.86326575, 190932.173988075, 196901.410646451, 203059.416196714, 209412.221990279, 215966.053901273, 222727.338654522, 229702.710361058, 236899.01726797, 244323.328729703, 251982.942408108, 259885.391708824, 268038.453461782, 276450.155853934, 285128.786622515, 294082.901517494, 303321.333042097, 312853.199480618, 322687.914223027, 332835.195396202, 343305.075811948, 354107.913242288, 365254.401032878, 376755.579065754, 388622.845082984, 400867.966383207, 413503.0919034, 426540.764698698, 439993.934833408, 453875.972696938, 468200.682758687, 482982.317776504, 498235.593473764, 513975.703700628, 530218.336095586, 546979.68826389, 564276.484490061, 582125.993002251, 600546.043806755, 619555.047111707, 639172.012359492, 659416.567888175, 680308.981242863, 701870.180158628, 724121.774237368, 747086.077341701, 770786.130729773, 795245.726955688, 820489.434561034, 846542.623583907, 873431.491912671, 901183.092512607, 929825.361554596, 959387.147475879, 989898.241004056, 1021389.40617639, 1053892.41238771, 1087440.06750118, 1122066.25205755, 1157805.95461937, 1194695.30828832, 1232771.62843468, 1272073.4516795, 1312640.57617139, 1354514.10320113, 1397736.48019894, 1442351.54516047, 1488404.57254966, 1535942.32072737, 1585013.08095741, 1635666.72804228, 1687954.77264353, 1741930.41534299, 1797648.60250319, 1855166.0839873, 1914541.47280086, 1975835.30671972, 2039110.11197075, 2104430.46903421, 2171863.08063883, 2241476.84202327, 2313342.91353984, 2387534.7956793, 2464128.40659767, 2543202.16222943, 2624837.05907362, 2709116.75974277, 2796127.68136741, 2885959.08695214, 2978703.17978238, 3074455.20098435, 3173313.53034429, 3275379.79049652, 3380758.95459358, 3489559.45757556, 3601893.31115985, 3717876.22267627, 3837627.71787719, 3961271.26785633, 4088934.42021464, 4220748.93461626, 4356850.92288235, 4497380.9937758, 4642484.40263485, 4792311.20601879, 4947016.42153518, 5106760.19302271, 5271707.96127078, 5442030.64046215, 5617904.80053212, 5799512.85564345, 5987043.25898364, 6180690.70409813, 6380656.33297957, 6587147.95114174, 6800380.24991402, 7020575.03619985, 7247961.46995183, 7482776.30962404, 7725264.16587129, 7975677.76377366, 8234278.21387548, 8501335.2923356, 8777127.73049851, 9061943.51420382, 9356080.19316424, 9659845.20075276, 9973556.18455114, 10297541.3480245, 10632139.8036982, 10977701.9382267, 11334589.7897579, 11703177.4380087, 12083851.4074825, 12477011.0842754, 12883069.1469299, 13302452.0118133, 13735600.2935145, 14182969.2807657, 14645029.4284192, 15122266.8660211, 15615183.9235469, 16124299.6748813, 16650150.4996439, 17193290.6639843, 17754292.9209912, 18333749.1313811, 18932270.9051555, 19550490.2649405, 20189060.3317438, 20848656.0338922, 21529974.8399387, 22233737.5163517, 22960688.9108324, 23711598.7621287, 24487262.5372515, 25288502.297021, 26116167.5909115, 26971136.38219, 27854316.0043797, 28766644.1501171, 29709089.8935041, 30682654.7470974, 31688373.7547154, 32727316.6212824, 33800588.8809731, 34909333.1049639, 36054730.1501399, 37238000.4501562, 38460405.3502961, 39723248.4876228, 41027877.2179684, 42375684.0913591, 43768108.3775304, 45206637.6432418, 46692809.3831607, 48228212.7061437, 49814490.0788087, 51453339.1283556, 53146514.5066573, 54895829.8177197, 56703159.6106723, 58570441.4405333, 60499677.9990625, 62492939.318107, 64552365.0479079, 66680166.812943, 68878630.6479553, 71150119.5169069, 73497075.9177057, 75922024.5756329, 78427575.2285159, 81016425.5067818, 83691363.9116489, 86455272.8948115, 89311132.0431006, 92262021.3717161, 95311124.7297536, 98461733.3218727, 101717249.350092, 105081189.779834, 108557190.234468, 112149009.022783, 115860531.303921, 119695773.394526, 123658887.222945, 127754164.935581, 131986043.660568, 136359110.434224, 140878107.295823, 145547936.556514, 150373666.248334, 155360535.759526, 160513961.66256, 165839543.741479, 171343071.22542, 177030529.235416, 182908105.451791, 188982197.00976, 195259417.631072, 201746604.999813, 208450828.390795, 215379396.5592, 222539865.900494, 229940048.889902, 237588022.811084, 245492138.78397, 253661031.102054, 262103626.889823, 270829156.091345, 279847161.801427, 289167510.951169, 298800405.360114, 308756393.167651, 319046380.656746, 329681644.483538, 340673844.32679, 352035035.971719, 363777684.84315, 375914680.00354, 388459348.631907, 401425471.000279, 414827295.964835, 428679556.989516, 442997488.720522, 457796844.130704, 473093912.253564, 488905536.527237, 505249133.769533, 522142713.805884, 539604899.77274, 557654949.119807, 576312775.335282, 595598970.419113, 615534828.130148, 636142368.033984, 657444360.379221, 679464351.830783, 702226692.089998, 725756561.432185, 750079999.193425, 775223933.23952, 801216210.451087, 828085628.260034, 855861967.273837, 884576025.025353, 914259650.88719, 944945782.190963, 976668481.593303, 1009462975.73181, 1043365695.21569, 1078414315.99749, 1114647802.17364, 1152106450.2637, 1190831935.01934, 1230867356.81639, 1272257290.68478, 1315047837.03334, 1359286674.12834, 1405023112.38662, 1452308150.54639, 1501194533.78104, 1551736813.82335, 1603991411.17007, 1658016679.43922, 1713872971.95486, 1771622710.63699, 1831330457.27652, 1893062987.27845, 1956889365.95915, 2022881027.48651, 2091111856.55497, 2161658272.8908, 2234599318.68596, 2310016749.06249, 2387995125.67334, 2468621913.54833, 2551987581.29884, 2638185704.79783, 2727313074.45655, 2819469806.22329, 2914759456.43365, 3013289140.647, 3115169656.60785, 3220515611.47605, 3329445553.47479, 3442082108.11036, 3558552119.12336, 3678986794.33635, 3803521856.56889, 3932297699.79673, 4065459550.73849, 4203157636.05897, 4345547355.38561, 4492789460.34089, 4645050239.80089, 4802501711.59749, 4965321820.88959, 5133694645.43599, 5307810608.01168, 5487866696.21676, 5674066689.93697, 5866621396.72281, 6065748895.36482, 6271674787.95117, 6484632460.7048, 6704863353.90668, 6932617241.22392, 7168152518.77123, 7411736504.24687, 7663645746.49542, 7924166345.86301, 8193594285.72244, 8472235775.5596, 8760407606.02633, 9058437516.37881, 9366664574.73556, 9685439571.60418, 10015125427.1421, 10356097612.6331, 10708744586.6767, 11073468246.6084, 11450684395.6832, 11840823226.5759, 12244329821.7715, 12661664671.436, 13093304209.384, 13539741367.7761, 14001486151.2039, 14479066230.8441, 14973027559.3854, 15483935007.4585, 16012373022.3237, 16558946309.5981, 17124280538.8328, 17709023073.7764, 18313843728.1939, 18939435548.1383, 19586515621.6052, 20255825916.5325, 20948134148.1437, 21664234676.6632, 22404949436.4764, 23171128897.8364, 23963653062.2659, 24783432492.8375, 25631409380.5605, 26508558648.1473, 27415889092.4702, 28354444567.0763, 29325305206.1678, 30329588691.5083, 31368451563.7686, 32443090579.8753, 33554744117.9848, 34704693631.76, 35894265155.6872, 37124830863.2332, 38397810679.7027, 39714673951.7287, 41076941175.3889, 42486185785.0178, 43944036004.8549, 45452176765.7454, 47012351689.1892, 48626365141.1128, 50296084357.8279, 52023441646.7212, 53810436664.3161, 55659138774.4363, 57571689489.3, 59550304996.4762, 61597278774.7284, 63714984301.8966, 65905877858.0593, 68172501427.3472, 70517485701.8953, 72943553191.5398, 75453521443.0037, 78050306372.4335, 80736925715.3055, 83516502597.8425, 86392269234.2453, 89367570754.186, 92445869165.1738, 95630747454.5627, 98925913836.1471, 102335206146.457, 105862596396.057, 109512195481.335, 113288258062.459, 117195187613.394, 121237541650.069, 125420037142.999, 129747556120.907, 134225151472.107, 138858052950.653, 143651673394.525, 148611615163.343, 153743676803.421, 159053859948.196, 164548376462.391, 170233655838.559, 176116352854.95, 182203355503.966, 188501793200.837, 195019045282.416, 201762749806.417, 208740812661.758, 215961417001.042, 223433033006.617, 231164428002.068, 239164676921.392, 247443173148.566, 256009639740.683, 264874141048.242, 274047094746.743, 283539284294.189, 293361871829.61, 303526411528.329, 314044863430.162, 324929607757.395, 336193459739.95, 347849684965.755, 359912015275.033, 372394665217.835, 385312349094.856, 398680298602.3, 412514281102.277, 426830618541.009, 441646207037.892, 456978537169.296, 472845714971.851, 489266483690.835, 506260246300.182, 523847088821.626, 542047804471.424, 560883918664.146, 580377714904.083, 600552261595.896, 621431439807.277, 643039972017.527, 665403451887.25, 688548375085.545, 712502171212.38, 737293236855.256, 762950969820.594, 789505804581.745, 816989248987.045, 845433922272.87, 874873594428.264, 905343226959.37, 936879015103.661, 969518431545.692, 1003300271687.99, 1038264700532.69, 1074453301231.27, 1111909125362.23, 1150676744998.12, 1190802306626.21, 1232333586988.64, 1275320050911.04, 1319812911190.4, 1365865190615.88, 1413531786198.93, 1462869535691.57, 1513937286474.67, 1566795966901.08, 1621508660181.34, 1678140680902.9, 1736759654277.2, 1797435598212.06, 1860241008310.58, 1925250945901.3, 1992543129208.04, 2062198027771.92, 2134298960241.9, 2208932195654.62, 2286187058328.27, 2366156036500.17, 2448934894841.96, 2534622790991.53, 2623322396245.44, 2715140020560.94, 2810185742022.21, 2908573540930.56, 3010421438684.67, 3115851641622.29, 3224990690001.53, 3337969612306, 3454924085064.6, 3575994598384.11, 3701326627399.05, 3831070809851.58, 3965383130021.14, 4104425109231.64, 4248364003172.69, 4397373006278.98, 4551631463421.42, 4711325089172.7, 4876646194919.07, 5047793924100.12, 5224974495868.79, 5408401457473.57, 5598295945676.98, 5794886957534.04, 5998411630868.31, 6209115534792.81, 6427252970637.73, 6653087283658.7, 6886891185913.28, 7128947090707.07};
std::vector<double> lookup (arr, arr + sizeof(arr) / sizeof(arr[0]) );


// [[Rcpp::export]]
double noverk(int n, int k){
  double res, root;
  int nLookup = lookup.size();
  root = lookup[0];
  //std::cout << root << '\n';
  if(n > nLookup){
    double nomin = 1, denom = 1;
    // comp nomin
    for(int i = n; i > k; i--){
      nomin *= std::pow(i,1/root);
      }
    for(int i = n-k; i > 0; i--){
      denom *= std::pow(i,1/root);
      }
    res = nomin/denom;
    } else {
    if((n != k) & (k > 0)){
      res = lookup[n] / (lookup[k]*lookup[n-k]);
      } else {
      res = 1;
    }
  }
  return(std::pow(res,root));
  }

