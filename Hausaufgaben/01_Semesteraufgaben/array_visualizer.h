#ifndef ARRAY_VISUALIZER_H
#define ARRAY_VISUALIZER_H
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "full_canvas.h"
#include "canvas.h"

/*
Ein Visualizer sammelt Arrays vom Typ unit8_t, die bei einem nicht erfolgreichen Test visualisiert werden.
*/
typedef struct Visualizer_ Visualizer;

/*
Füge eine Kopie des übergebenen uint8_t Array zum Visualizer hinzu.
Jedes zugefügte Array wird im Bild als Zeile von grauen Quadraten dargestellt. Je größer
eine Zahl im Array, desto heller ihr Quadrat.
Jeder Aufruf dieser Funktion fügt eine neue Zeile zum Bild hinzu.

Wenn Sie Zeilen hinzufügen, obwohl die Lösung der Aufgabe weniger Zeilen verlangt, werden Ihre zusätzlichen Zeilen ignoriert.
*/
void visualizer_append_array(Visualizer *v, uint8_t *arr);





/*
Implementation details below.
*/

#define PIXEL 12
// #define PIXEL 1

typedef enum ColorScheme_ {
    BW,
    Virdis,
    Cubehelix,
    Inferno,
    Parula,
} ColorScheme;

#define SCHEMES 5

ColorScheme color_schemes[] = {BW, Virdis, Cubehelix, Inferno, Parula};

struct Visualizer_ {
    size_t arr_len;
    size_t arr_num;
    size_t current;
    uint8_t *arrs;
    ColorScheme colors;
    size_t pixel_size;
};

Visualizer new_visualizer(size_t arr_len, size_t arr_num) {
    Visualizer v;
    v.arr_len = arr_len;
    v.arr_num = arr_num;
    v.current = 0;
    v.colors = BW;
    v.pixel_size = PIXEL;
    v.arrs = (uint8_t *) malloc(arr_num * arr_len);

    for (size_t i = 0; i < arr_num; i++) {
        for (size_t j = 0; j < arr_len; j++) {
            v.arrs[i * v.arr_len + j] = 255;
        }
    }

    return v;
}

void visualizer_append_array(Visualizer *v, uint8_t *arr) {
    // printf("len %ld, totalcount %ld, current %ld\n", v->arr_len, v->arr_num, v->current);
    if (v->current < v->arr_num) {
        memcpy(v->arrs + (v->current * v->arr_len), arr, v->arr_len);
        v->current += 1;
    }
}

// color maps from https://github.com/yuki-koyama/tinycolormap/blob/master/include/tinycolormap.hpp
float colormap_inferno[256 * 3] = {
    0.001462, 0.000466, 0.013866,
    0.002267, 0.001270, 0.018570,
    0.003299, 0.002249, 0.024239,
    0.004547, 0.003392, 0.030909,
    0.006006, 0.004692, 0.038558,
    0.007676, 0.006136, 0.046836,
    0.009561, 0.007713, 0.055143,
    0.011663, 0.009417, 0.063460,
    0.013995, 0.011225, 0.071862,
    0.016561, 0.013136, 0.080282,
    0.019373, 0.015133, 0.088767,
    0.022447, 0.017199, 0.097327,
    0.025793, 0.019331, 0.105930,
    0.029432, 0.021503, 0.114621,
    0.033385, 0.023702, 0.123397,
    0.037668, 0.025921, 0.132232,
    0.042253, 0.028139, 0.141141,
    0.046915, 0.030324, 0.150164,
    0.051644, 0.032474, 0.159254,
    0.056449, 0.034569, 0.168414,
    0.061340, 0.036590, 0.177642,
    0.066331, 0.038504, 0.186962,
    0.071429, 0.040294, 0.196354,
    0.076637, 0.041905, 0.205799,
    0.081962, 0.043328, 0.215289,
    0.087411, 0.044556, 0.224813,
    0.092990, 0.045583, 0.234358,
    0.098702, 0.046402, 0.243904,
    0.104551, 0.047008, 0.253430,
    0.110536, 0.047399, 0.262912,
    0.116656, 0.047574, 0.272321,
    0.122908, 0.047536, 0.281624,
    0.129285, 0.047293, 0.290788,
    0.135778, 0.046856, 0.299776,
    0.142378, 0.046242, 0.308553,
    0.149073, 0.045468, 0.317085,
    0.155850, 0.044559, 0.325338,
    0.162689, 0.043554, 0.333277,
    0.169575, 0.042489, 0.340874,
    0.176493, 0.041402, 0.348111,
    0.183429, 0.040329, 0.354971,
    0.190367, 0.039309, 0.361447,
    0.197297, 0.038400, 0.367535,
    0.204209, 0.037632, 0.373238,
    0.211095, 0.037030, 0.378563,
    0.217949, 0.036615, 0.383522,
    0.224763, 0.036405, 0.388129,
    0.231538, 0.036405, 0.392400,
    0.238273, 0.036621, 0.396353,
    0.244967, 0.037055, 0.400007,
    0.251620, 0.037705, 0.403378,
    0.258234, 0.038571, 0.406485,
    0.264810, 0.039647, 0.409345,
    0.271347, 0.040922, 0.411976,
    0.277850, 0.042353, 0.414392,
    0.284321, 0.043933, 0.416608,
    0.290763, 0.045644, 0.418637,
    0.297178, 0.047470, 0.420491,
    0.303568, 0.049396, 0.422182,
    0.309935, 0.051407, 0.423721,
    0.316282, 0.053490, 0.425116,
    0.322610, 0.055634, 0.426377,
    0.328921, 0.057827, 0.427511,
    0.335217, 0.060060, 0.428524,
    0.341500, 0.062325, 0.429425,
    0.347771, 0.064616, 0.430217,
    0.354032, 0.066925, 0.430906,
    0.360284, 0.069247, 0.431497,
    0.366529, 0.071579, 0.431994,
    0.372768, 0.073915, 0.432400,
    0.379001, 0.076253, 0.432719,
    0.385228, 0.078591, 0.432955,
    0.391453, 0.080927, 0.433109,
    0.397674, 0.083257, 0.433183,
    0.403894, 0.085580, 0.433179,
    0.410113, 0.087896, 0.433098,
    0.416331, 0.090203, 0.432943,
    0.422549, 0.092501, 0.432714,
    0.428768, 0.094790, 0.432412,
    0.434987, 0.097069, 0.432039,
    0.441207, 0.099338, 0.431594,
    0.447428, 0.101597, 0.431080,
    0.453651, 0.103848, 0.430498,
    0.459875, 0.106089, 0.429846,
    0.466100, 0.108322, 0.429125,
    0.472328, 0.110547, 0.428334,
    0.478558, 0.112764, 0.427475,
    0.484789, 0.114974, 0.426548,
    0.491022, 0.117179, 0.425552,
    0.497257, 0.119379, 0.424488,
    0.503493, 0.121575, 0.423356,
    0.509730, 0.123769, 0.422156,
    0.515967, 0.125960, 0.420887,
    0.522206, 0.128150, 0.419549,
    0.528444, 0.130341, 0.418142,
    0.534683, 0.132534, 0.416667,
    0.540920, 0.134729, 0.415123,
    0.547157, 0.136929, 0.413511,
    0.553392, 0.139134, 0.411829,
    0.559624, 0.141346, 0.410078,
    0.565854, 0.143567, 0.408258,
    0.572081, 0.145797, 0.406369,
    0.578304, 0.148039, 0.404411,
    0.584521, 0.150294, 0.402385,
    0.590734, 0.152563, 0.400290,
    0.596940, 0.154848, 0.398125,
    0.603139, 0.157151, 0.395891,
    0.609330, 0.159474, 0.393589,
    0.615513, 0.161817, 0.391219,
    0.621685, 0.164184, 0.388781,
    0.627847, 0.166575, 0.386276,
    0.633998, 0.168992, 0.383704,
    0.640135, 0.171438, 0.381065,
    0.646260, 0.173914, 0.378359,
    0.652369, 0.176421, 0.375586,
    0.658463, 0.178962, 0.372748,
    0.664540, 0.181539, 0.369846,
    0.670599, 0.184153, 0.366879,
    0.676638, 0.186807, 0.363849,
    0.682656, 0.189501, 0.360757,
    0.688653, 0.192239, 0.357603,
    0.694627, 0.195021, 0.354388,
    0.700576, 0.197851, 0.351113,
    0.706500, 0.200728, 0.347777,
    0.712396, 0.203656, 0.344383,
    0.718264, 0.206636, 0.340931,
    0.724103, 0.209670, 0.337424,
    0.729909, 0.212759, 0.333861,
    0.735683, 0.215906, 0.330245,
    0.741423, 0.219112, 0.326576,
    0.747127, 0.222378, 0.322856,
    0.752794, 0.225706, 0.319085,
    0.758422, 0.229097, 0.315266,
    0.764010, 0.232554, 0.311399,
    0.769556, 0.236077, 0.307485,
    0.775059, 0.239667, 0.303526,
    0.780517, 0.243327, 0.299523,
    0.785929, 0.247056, 0.295477,
    0.791293, 0.250856, 0.291390,
    0.796607, 0.254728, 0.287264,
    0.801871, 0.258674, 0.283099,
    0.807082, 0.262692, 0.278898,
    0.812239, 0.266786, 0.274661,
    0.817341, 0.270954, 0.270390,
    0.822386, 0.275197, 0.266085,
    0.827372, 0.279517, 0.261750,
    0.832299, 0.283913, 0.257383,
    0.837165, 0.288385, 0.252988,
    0.841969, 0.292933, 0.248564,
    0.846709, 0.297559, 0.244113,
    0.851384, 0.302260, 0.239636,
    0.855992, 0.307038, 0.235133,
    0.860533, 0.311892, 0.230606,
    0.865006, 0.316822, 0.226055,
    0.869409, 0.321827, 0.221482,
    0.873741, 0.326906, 0.216886,
    0.878001, 0.332060, 0.212268,
    0.882188, 0.337287, 0.207628,
    0.886302, 0.342586, 0.202968,
    0.890341, 0.347957, 0.198286,
    0.894305, 0.353399, 0.193584,
    0.898192, 0.358911, 0.188860,
    0.902003, 0.364492, 0.184116,
    0.905735, 0.370140, 0.179350,
    0.909390, 0.375856, 0.174563,
    0.912966, 0.381636, 0.169755,
    0.916462, 0.387481, 0.164924,
    0.919879, 0.393389, 0.160070,
    0.923215, 0.399359, 0.155193,
    0.926470, 0.405389, 0.150292,
    0.929644, 0.411479, 0.145367,
    0.932737, 0.417627, 0.140417,
    0.935747, 0.423831, 0.135440,
    0.938675, 0.430091, 0.130438,
    0.941521, 0.436405, 0.125409,
    0.944285, 0.442772, 0.120354,
    0.946965, 0.449191, 0.115272,
    0.949562, 0.455660, 0.110164,
    0.952075, 0.462178, 0.105031,
    0.954506, 0.468744, 0.099874,
    0.956852, 0.475356, 0.094695,
    0.959114, 0.482014, 0.089499,
    0.961293, 0.488716, 0.084289,
    0.963387, 0.495462, 0.079073,
    0.965397, 0.502249, 0.073859,
    0.967322, 0.509078, 0.068659,
    0.969163, 0.515946, 0.063488,
    0.970919, 0.522853, 0.058367,
    0.972590, 0.529798, 0.053324,
    0.974176, 0.536780, 0.048392,
    0.975677, 0.543798, 0.043618,
    0.977092, 0.550850, 0.039050,
    0.978422, 0.557937, 0.034931,
    0.979666, 0.565057, 0.031409,
    0.980824, 0.572209, 0.028508,
    0.981895, 0.579392, 0.026250,
    0.982881, 0.586606, 0.024661,
    0.983779, 0.593849, 0.023770,
    0.984591, 0.601122, 0.023606,
    0.985315, 0.608422, 0.024202,
    0.985952, 0.615750, 0.025592,
    0.986502, 0.623105, 0.027814,
    0.986964, 0.630485, 0.030908,
    0.987337, 0.637890, 0.034916,
    0.987622, 0.645320, 0.039886,
    0.987819, 0.652773, 0.045581,
    0.987926, 0.660250, 0.051750,
    0.987945, 0.667748, 0.058329,
    0.987874, 0.675267, 0.065257,
    0.987714, 0.682807, 0.072489,
    0.987464, 0.690366, 0.079990,
    0.987124, 0.697944, 0.087731,
    0.986694, 0.705540, 0.095694,
    0.986175, 0.713153, 0.103863,
    0.985566, 0.720782, 0.112229,
    0.984865, 0.728427, 0.120785,
    0.984075, 0.736087, 0.129527,
    0.983196, 0.743758, 0.138453,
    0.982228, 0.751442, 0.147565,
    0.981173, 0.759135, 0.156863,
    0.980032, 0.766837, 0.166353,
    0.978806, 0.774545, 0.176037,
    0.977497, 0.782258, 0.185923,
    0.976108, 0.789974, 0.196018,
    0.974638, 0.797692, 0.206332,
    0.973088, 0.805409, 0.216877,
    0.971468, 0.813122, 0.227658,
    0.969783, 0.820825, 0.238686,
    0.968041, 0.828515, 0.249972,
    0.966243, 0.836191, 0.261534,
    0.964394, 0.843848, 0.273391,
    0.962517, 0.851476, 0.285546,
    0.960626, 0.859069, 0.298010,
    0.958720, 0.866624, 0.310820,
    0.956834, 0.874129, 0.323974,
    0.954997, 0.881569, 0.337475,
    0.953215, 0.888942, 0.351369,
    0.951546, 0.896226, 0.365627,
    0.950018, 0.903409, 0.380271,
    0.948683, 0.910473, 0.395289,
    0.947594, 0.917399, 0.410665,
    0.946809, 0.924168, 0.426373,
    0.946392, 0.930761, 0.442367,
    0.946403, 0.937159, 0.458592,
    0.946903, 0.943348, 0.474970,
    0.947937, 0.949318, 0.491426,
    0.949545, 0.955063, 0.507860,
    0.951740, 0.960587, 0.524203,
    0.954529, 0.965896, 0.540361,
    0.957896, 0.971003, 0.556275,
    0.961812, 0.975924, 0.571925,
    0.966249, 0.980678, 0.587206,
    0.971162, 0.985282, 0.602154,
    0.976511, 0.989753, 0.616760,
    0.982257, 0.994109, 0.631017,
    0.988362, 0.998364, 0.644924
};

float colormap_virdis[256 * 3] = {
    0.267004, 0.004874, 0.329415,
    0.268510, 0.009605, 0.335427,
    0.269944, 0.014625, 0.341379,
    0.271305, 0.019942, 0.347269,
    0.272594, 0.025563, 0.353093,
    0.273809, 0.031497, 0.358853,
    0.274952, 0.037752, 0.364543,
    0.276022, 0.044167, 0.370164,
    0.277018, 0.050344, 0.375715,
    0.277941, 0.056324, 0.381191,
    0.278791, 0.062145, 0.386592,
    0.279566, 0.067836, 0.391917,
    0.280267, 0.073417, 0.397163,
    0.280894, 0.078907, 0.402329,
    0.281446, 0.084320, 0.407414,
    0.281924, 0.089666, 0.412415,
    0.282327, 0.094955, 0.417331,
    0.282656, 0.100196, 0.422160,
    0.282910, 0.105393, 0.426902,
    0.283091, 0.110553, 0.431554,
    0.283197, 0.115680, 0.436115,
    0.283229, 0.120777, 0.440584,
    0.283187, 0.125848, 0.444960,
    0.283072, 0.130895, 0.449241,
    0.282884, 0.135920, 0.453427,
    0.282623, 0.140926, 0.457517,
    0.282290, 0.145912, 0.461510,
    0.281887, 0.150881, 0.465405,
    0.281412, 0.155834, 0.469201,
    0.280868, 0.160771, 0.472899,
    0.280255, 0.165693, 0.476498,
    0.279574, 0.170599, 0.479997,
    0.278826, 0.175490, 0.483397,
    0.278012, 0.180367, 0.486697,
    0.277134, 0.185228, 0.489898,
    0.276194, 0.190074, 0.493001,
    0.275191, 0.194905, 0.496005,
    0.274128, 0.199721, 0.498911,
    0.273006, 0.204520, 0.501721,
    0.271828, 0.209303, 0.504434,
    0.270595, 0.214069, 0.507052,
    0.269308, 0.218818, 0.509577,
    0.267968, 0.223549, 0.512008,
    0.266580, 0.228262, 0.514349,
    0.265145, 0.232956, 0.516599,
    0.263663, 0.237631, 0.518762,
    0.262138, 0.242286, 0.520837,
    0.260571, 0.246922, 0.522828,
    0.258965, 0.251537, 0.524736,
    0.257322, 0.256130, 0.526563,
    0.255645, 0.260703, 0.528312,
    0.253935, 0.265254, 0.529983,
    0.252194, 0.269783, 0.531579,
    0.250425, 0.274290, 0.533103,
    0.248629, 0.278775, 0.534556,
    0.246811, 0.283237, 0.535941,
    0.244972, 0.287675, 0.537260,
    0.243113, 0.292092, 0.538516,
    0.241237, 0.296485, 0.539709,
    0.239346, 0.300855, 0.540844,
    0.237441, 0.305202, 0.541921,
    0.235526, 0.309527, 0.542944,
    0.233603, 0.313828, 0.543914,
    0.231674, 0.318106, 0.544834,
    0.229739, 0.322361, 0.545706,
    0.227802, 0.326594, 0.546532,
    0.225863, 0.330805, 0.547314,
    0.223925, 0.334994, 0.548053,
    0.221989, 0.339161, 0.548752,
    0.220057, 0.343307, 0.549413,
    0.218130, 0.347432, 0.550038,
    0.216210, 0.351535, 0.550627,
    0.214298, 0.355619, 0.551184,
    0.212395, 0.359683, 0.551710,
    0.210503, 0.363727, 0.552206,
    0.208623, 0.367752, 0.552675,
    0.206756, 0.371758, 0.553117,
    0.204903, 0.375746, 0.553533,
    0.203063, 0.379716, 0.553925,
    0.201239, 0.383670, 0.554294,
    0.199430, 0.387607, 0.554642,
    0.197636, 0.391528, 0.554969,
    0.195860, 0.395433, 0.555276,
    0.194100, 0.399323, 0.555565,
    0.192357, 0.403199, 0.555836,
    0.190631, 0.407061, 0.556089,
    0.188923, 0.410910, 0.556326,
    0.187231, 0.414746, 0.556547,
    0.185556, 0.418570, 0.556753,
    0.183898, 0.422383, 0.556944,
    0.182256, 0.426184, 0.557120,
    0.180629, 0.429975, 0.557282,
    0.179019, 0.433756, 0.557430,
    0.177423, 0.437527, 0.557565,
    0.175841, 0.441290, 0.557685,
    0.174274, 0.445044, 0.557792,
    0.172719, 0.448791, 0.557885,
    0.171176, 0.452530, 0.557965,
    0.169646, 0.456262, 0.558030,
    0.168126, 0.459988, 0.558082,
    0.166617, 0.463708, 0.558119,
    0.165117, 0.467423, 0.558141,
    0.163625, 0.471133, 0.558148,
    0.162142, 0.474838, 0.558140,
    0.160665, 0.478540, 0.558115,
    0.159194, 0.482237, 0.558073,
    0.157729, 0.485932, 0.558013,
    0.156270, 0.489624, 0.557936,
    0.154815, 0.493313, 0.557840,
    0.153364, 0.497000, 0.557724,
    0.151918, 0.500685, 0.557587,
    0.150476, 0.504369, 0.557430,
    0.149039, 0.508051, 0.557250,
    0.147607, 0.511733, 0.557049,
    0.146180, 0.515413, 0.556823,
    0.144759, 0.519093, 0.556572,
    0.143343, 0.522773, 0.556295,
    0.141935, 0.526453, 0.555991,
    0.140536, 0.530132, 0.555659,
    0.139147, 0.533812, 0.555298,
    0.137770, 0.537492, 0.554906,
    0.136408, 0.541173, 0.554483,
    0.135066, 0.544853, 0.554029,
    0.133743, 0.548535, 0.553541,
    0.132444, 0.552216, 0.553018,
    0.131172, 0.555899, 0.552459,
    0.129933, 0.559582, 0.551864,
    0.128729, 0.563265, 0.551229,
    0.127568, 0.566949, 0.550556,
    0.126453, 0.570633, 0.549841,
    0.125394, 0.574318, 0.549086,
    0.124395, 0.578002, 0.548287,
    0.123463, 0.581687, 0.547445,
    0.122606, 0.585371, 0.546557,
    0.121831, 0.589055, 0.545623,
    0.121148, 0.592739, 0.544641,
    0.120565, 0.596422, 0.543611,
    0.120092, 0.600104, 0.542530,
    0.119738, 0.603785, 0.541400,
    0.119512, 0.607464, 0.540218,
    0.119423, 0.611141, 0.538982,
    0.119483, 0.614817, 0.537692,
    0.119699, 0.618490, 0.536347,
    0.120081, 0.622161, 0.534946,
    0.120638, 0.625828, 0.533488,
    0.121380, 0.629492, 0.531973,
    0.122312, 0.633153, 0.530398,
    0.123444, 0.636809, 0.528763,
    0.124780, 0.640461, 0.527068,
    0.126326, 0.644107, 0.525311,
    0.128087, 0.647749, 0.523491,
    0.130067, 0.651384, 0.521608,
    0.132268, 0.655014, 0.519661,
    0.134692, 0.658636, 0.517649,
    0.137339, 0.662252, 0.515571,
    0.140210, 0.665859, 0.513427,
    0.143303, 0.669459, 0.511215,
    0.146616, 0.673050, 0.508936,
    0.150148, 0.676631, 0.506589,
    0.153894, 0.680203, 0.504172,
    0.157851, 0.683765, 0.501686,
    0.162016, 0.687316, 0.499129,
    0.166383, 0.690856, 0.496502,
    0.170948, 0.694384, 0.493803,
    0.175707, 0.697900, 0.491033,
    0.180653, 0.701402, 0.488189,
    0.185783, 0.704891, 0.485273,
    0.191090, 0.708366, 0.482284,
    0.196571, 0.711827, 0.479221,
    0.202219, 0.715272, 0.476084,
    0.208030, 0.718701, 0.472873,
    0.214000, 0.722114, 0.469588,
    0.220124, 0.725509, 0.466226,
    0.226397, 0.728888, 0.462789,
    0.232815, 0.732247, 0.459277,
    0.239374, 0.735588, 0.455688,
    0.246070, 0.738910, 0.452024,
    0.252899, 0.742211, 0.448284,
    0.259857, 0.745492, 0.444467,
    0.266941, 0.748751, 0.440573,
    0.274149, 0.751988, 0.436601,
    0.281477, 0.755203, 0.432552,
    0.288921, 0.758394, 0.428426,
    0.296479, 0.761561, 0.424223,
    0.304148, 0.764704, 0.419943,
    0.311925, 0.767822, 0.415586,
    0.319809, 0.770914, 0.411152,
    0.327796, 0.773980, 0.406640,
    0.335885, 0.777018, 0.402049,
    0.344074, 0.780029, 0.397381,
    0.352360, 0.783011, 0.392636,
    0.360741, 0.785964, 0.387814,
    0.369214, 0.788888, 0.382914,
    0.377779, 0.791781, 0.377939,
    0.386433, 0.794644, 0.372886,
    0.395174, 0.797475, 0.367757,
    0.404001, 0.800275, 0.362552,
    0.412913, 0.803041, 0.357269,
    0.421908, 0.805774, 0.351910,
    0.430983, 0.808473, 0.346476,
    0.440137, 0.811138, 0.340967,
    0.449368, 0.813768, 0.335384,
    0.458674, 0.816363, 0.329727,
    0.468053, 0.818921, 0.323998,
    0.477504, 0.821444, 0.318195,
    0.487026, 0.823929, 0.312321,
    0.496615, 0.826376, 0.306377,
    0.506271, 0.828786, 0.300362,
    0.515992, 0.831158, 0.294279,
    0.525776, 0.833491, 0.288127,
    0.535621, 0.835785, 0.281908,
    0.545524, 0.838039, 0.275626,
    0.555484, 0.840254, 0.269281,
    0.565498, 0.842430, 0.262877,
    0.575563, 0.844566, 0.256415,
    0.585678, 0.846661, 0.249897,
    0.595839, 0.848717, 0.243329,
    0.606045, 0.850733, 0.236712,
    0.616293, 0.852709, 0.230052,
    0.626579, 0.854645, 0.223353,
    0.636902, 0.856542, 0.216620,
    0.647257, 0.858400, 0.209861,
    0.657642, 0.860219, 0.203082,
    0.668054, 0.861999, 0.196293,
    0.678489, 0.863742, 0.189503,
    0.688944, 0.865448, 0.182725,
    0.699415, 0.867117, 0.175971,
    0.709898, 0.868751, 0.169257,
    0.720391, 0.870350, 0.162603,
    0.730889, 0.871916, 0.156029,
    0.741388, 0.873449, 0.149561,
    0.751884, 0.874951, 0.143228,
    0.762373, 0.876424, 0.137064,
    0.772852, 0.877868, 0.131109,
    0.783315, 0.879285, 0.125405,
    0.793760, 0.880678, 0.120005,
    0.804182, 0.882046, 0.114965,
    0.814576, 0.883393, 0.110347,
    0.824940, 0.884720, 0.106217,
    0.835270, 0.886029, 0.102646,
    0.845561, 0.887322, 0.099702,
    0.855810, 0.888601, 0.097452,
    0.866013, 0.889868, 0.095953,
    0.876168, 0.891125, 0.095250,
    0.886271, 0.892374, 0.095374,
    0.896320, 0.893616, 0.096335,
    0.906311, 0.894855, 0.098125,
    0.916242, 0.896091, 0.100717,
    0.926106, 0.897330, 0.104071,
    0.935904, 0.898570, 0.108131,
    0.945636, 0.899815, 0.112838,
    0.955300, 0.901065, 0.118128,
    0.964894, 0.902323, 0.123941,
    0.974417, 0.903590, 0.130215,
    0.983868, 0.904867, 0.136897,
    0.993248, 0.906157, 0.143936,
};

float colormap_cubehelix[256 * 3] = {
    0.000000, 0.000000, 0.000000 ,
    0.006716, 0.002119, 0.005970 ,
    0.013252, 0.004287, 0.012162 ,
    0.019599, 0.006514, 0.018563 ,
    0.025748, 0.008803, 0.025162 ,
    0.031691, 0.011164, 0.031946 ,
    0.037421, 0.013600, 0.038902 ,
    0.042932, 0.016118, 0.046016 ,
    0.048217, 0.018724, 0.053275 ,
    0.053271, 0.021423, 0.060666 ,
    0.058090, 0.024220, 0.068173 ,
    0.062670, 0.027119, 0.075781 ,
    0.067008, 0.030126, 0.083478 ,
    0.071101, 0.033243, 0.091246 ,
    0.074947, 0.036475, 0.099072 ,
    0.078546, 0.039824, 0.106939 ,
    0.081898, 0.043295, 0.114834 ,
    0.085002, 0.046889, 0.122740 ,
    0.087860, 0.050609, 0.130643 ,
    0.090474, 0.054457, 0.138527 ,
    0.092845, 0.058434, 0.146378 ,
    0.094978, 0.062542, 0.154180 ,
    0.096875, 0.066781, 0.161918 ,
    0.098542, 0.071152, 0.169579 ,
    0.099984, 0.075655, 0.177147 ,
    0.101205, 0.080290, 0.184609 ,
    0.102212, 0.085055, 0.191951 ,
    0.103013, 0.089951, 0.199159 ,
    0.103615, 0.094975, 0.206221 ,
    0.104025, 0.100126, 0.213124 ,
    0.104252, 0.105403, 0.219855 ,
    0.104305, 0.110801, 0.226402 ,
    0.104194, 0.116320, 0.232755 ,
    0.103929, 0.121956, 0.238903 ,
    0.103519, 0.127705, 0.244834 ,
    0.102976, 0.133564, 0.250541 ,
    0.102310, 0.139529, 0.256012 ,
    0.101534, 0.145596, 0.261240 ,
    0.100659, 0.151759, 0.266217 ,
    0.099697, 0.158016, 0.270935 ,
    0.098661, 0.164359, 0.275388 ,
    0.097563, 0.170785, 0.279569 ,
    0.096415, 0.177287, 0.283474 ,
    0.095232, 0.183860, 0.287097 ,
    0.094026, 0.190498, 0.290434 ,
    0.092810, 0.197194, 0.293483 ,
    0.091597, 0.203943, 0.296240 ,
    0.090402, 0.210739, 0.298703 ,
    0.089237, 0.217573, 0.300873 ,
    0.088115, 0.224441, 0.302747 ,
    0.087051, 0.231334, 0.304327 ,
    0.086056, 0.238247, 0.305612 ,
    0.085146, 0.245171, 0.306606 ,
    0.084331, 0.252101, 0.307310 ,
    0.083626, 0.259028, 0.307728 ,
    0.083043, 0.265946, 0.307863 ,
    0.082594, 0.272848, 0.307720 ,
    0.082291, 0.279726, 0.307304 ,
    0.082148, 0.286573, 0.306621 ,
    0.082174, 0.293383, 0.305677 ,
    0.082381, 0.300147, 0.304480 ,
    0.082780, 0.306860, 0.303037 ,
    0.083383, 0.313514, 0.301356 ,
    0.084198, 0.320102, 0.299448 ,
    0.085235, 0.326618, 0.297320 ,
    0.086504, 0.333055, 0.294984 ,
    0.088014, 0.339406, 0.292449 ,
    0.089772, 0.345666, 0.289728 ,
    0.091787, 0.351829, 0.286831 ,
    0.094066, 0.357887, 0.283771 ,
    0.096615, 0.363836, 0.280560 ,
    0.099441, 0.369671, 0.277211 ,
    0.102549, 0.375385, 0.273736 ,
    0.105944, 0.380974, 0.270151 ,
    0.109630, 0.386433, 0.266468 ,
    0.113611, 0.391757, 0.262703 ,
    0.117891, 0.396943, 0.258868 ,
    0.122472, 0.401985, 0.254979 ,
    0.127356, 0.406881, 0.251051 ,
    0.132543, 0.411627, 0.247099 ,
    0.138035, 0.416220, 0.243137 ,
    0.143832, 0.420656, 0.239182 ,
    0.149933, 0.424934, 0.235247 ,
    0.156336, 0.429052, 0.231350 ,
    0.163040, 0.433007, 0.227504 ,
    0.170042, 0.436798, 0.223726 ,
    0.177339, 0.440423, 0.220029 ,
    0.184927, 0.443882, 0.216431 ,
    0.192802, 0.447175, 0.212944 ,
    0.200958, 0.450301, 0.209585 ,
    0.209391, 0.453260, 0.206367 ,
    0.218092, 0.456053, 0.203306 ,
    0.227057, 0.458680, 0.200415 ,
    0.236277, 0.461144, 0.197707 ,
    0.245744, 0.463444, 0.195197 ,
    0.255451, 0.465584, 0.192898 ,
    0.265388, 0.467565, 0.190822 ,
    0.275545, 0.469391, 0.188982 ,
    0.285913, 0.471062, 0.187389 ,
    0.296481, 0.472584, 0.186055 ,
    0.307239, 0.473959, 0.184992 ,
    0.318175, 0.475191, 0.184208 ,
    0.329277, 0.476285, 0.183716 ,
    0.340534, 0.477243, 0.183523 ,
    0.351934, 0.478072, 0.183638 ,
    0.363463, 0.478776, 0.184071 ,
    0.375109, 0.479360, 0.184829 ,
    0.386858, 0.479829, 0.185918 ,
    0.398697, 0.480190, 0.187345 ,
    0.410613, 0.480448, 0.189115 ,
    0.422591, 0.480609, 0.191235 ,
    0.434618, 0.480679, 0.193708 ,
    0.446680, 0.480665, 0.196538 ,
    0.458762, 0.480574, 0.199728 ,
    0.470850, 0.480412, 0.203280 ,
    0.482930, 0.480186, 0.207197 ,
    0.494987, 0.479903, 0.211478 ,
    0.507008, 0.479572, 0.216124 ,
    0.518978, 0.479198, 0.221136 ,
    0.530883, 0.478789, 0.226510 ,
    0.542708, 0.478353, 0.232247 ,
    0.554441, 0.477898, 0.238342 ,
    0.566067, 0.477430, 0.244794 ,
    0.577573, 0.476958, 0.251597 ,
    0.588945, 0.476490, 0.258747 ,
    0.600171, 0.476032, 0.266239 ,
    0.611237, 0.475592, 0.274067 ,
    0.622132, 0.475178, 0.282223 ,
    0.632842, 0.474798, 0.290702 ,
    0.643357, 0.474459, 0.299495 ,
    0.653665, 0.474168, 0.308593 ,
    0.663755, 0.473933, 0.317987 ,
    0.673616, 0.473761, 0.327668 ,
    0.683239, 0.473658, 0.337626 ,
    0.692613, 0.473632, 0.347849 ,
    0.701729, 0.473690, 0.358327 ,
    0.710579, 0.473838, 0.369047 ,
    0.719155, 0.474083, 0.379998 ,
    0.727448, 0.474430, 0.391167 ,
    0.735453, 0.474886, 0.402541 ,
    0.743162, 0.475457, 0.414106 ,
    0.750569, 0.476148, 0.425849 ,
    0.757669, 0.476964, 0.437755 ,
    0.764458, 0.477911, 0.449811 ,
    0.770932, 0.478994, 0.462001 ,
    0.777086, 0.480216, 0.474310 ,
    0.782918, 0.481583, 0.486725 ,
    0.788426, 0.483098, 0.499228 ,
    0.793609, 0.484765, 0.511805 ,
    0.798465, 0.486587, 0.524441 ,
    0.802993, 0.488567, 0.537119 ,
    0.807196, 0.490708, 0.549824 ,
    0.811072, 0.493013, 0.562540 ,
    0.814625, 0.495483, 0.575253 ,
    0.817855, 0.498121, 0.587945 ,
    0.820767, 0.500927, 0.600602 ,
    0.823364, 0.503903, 0.613208 ,
    0.825649, 0.507050, 0.625748 ,
    0.827628, 0.510368, 0.638207 ,
    0.829305, 0.513857, 0.650570 ,
    0.830688, 0.517516, 0.662822 ,
    0.831781, 0.521346, 0.674949 ,
    0.832593, 0.525345, 0.686938 ,
    0.833130, 0.529511, 0.698773 ,
    0.833402, 0.533844, 0.710443 ,
    0.833416, 0.538342, 0.721933 ,
    0.833181, 0.543001, 0.733232 ,
    0.832708, 0.547820, 0.744327 ,
    0.832006, 0.552795, 0.755206 ,
    0.831086, 0.557924, 0.765859 ,
    0.829958, 0.563202, 0.776274 ,
    0.828633, 0.568627, 0.786443 ,
    0.827124, 0.574193, 0.796354 ,
    0.825442, 0.579897, 0.805999 ,
    0.823599, 0.585733, 0.815370 ,
    0.821608, 0.591698, 0.824459 ,
    0.819482, 0.597785, 0.833258 ,
    0.817233, 0.603990, 0.841761 ,
    0.814875, 0.610307, 0.849963 ,
    0.812421, 0.616730, 0.857858 ,
    0.809884, 0.623252, 0.865441 ,
    0.807278, 0.629869, 0.872709 ,
    0.804617, 0.636573, 0.879658 ,
    0.801914, 0.643359, 0.886286 ,
    0.799183, 0.650218, 0.892592 ,
    0.796438, 0.657146, 0.898574 ,
    0.793692, 0.664134, 0.904231 ,
    0.790959, 0.671176, 0.909565 ,
    0.788253, 0.678264, 0.914576 ,
    0.785586, 0.685392, 0.919267 ,
    0.782973, 0.692553, 0.923639 ,
    0.780425, 0.699738, 0.927695 ,
    0.777957, 0.706942, 0.931441 ,
    0.775579, 0.714157, 0.934879 ,
    0.773305, 0.721375, 0.938016 ,
    0.771147, 0.728589, 0.940857 ,
    0.769116, 0.735793, 0.943409 ,
    0.767224, 0.742979, 0.945678 ,
    0.765481, 0.750140, 0.947673 ,
    0.763898, 0.757269, 0.949402 ,
    0.762485, 0.764360, 0.950874 ,
    0.761251, 0.771405, 0.952098 ,
    0.760207, 0.778399, 0.953084 ,
    0.759360, 0.785335, 0.953843 ,
    0.758718, 0.792207, 0.954386 ,
    0.758290, 0.799008, 0.954724 ,
    0.758082, 0.805734, 0.954869 ,
    0.758101, 0.812378, 0.954833 ,
    0.758353, 0.818934, 0.954629 ,
    0.758842, 0.825399, 0.954270 ,
    0.759575, 0.831767, 0.953769 ,
    0.760554, 0.838033, 0.953140 ,
    0.761784, 0.844192, 0.952397 ,
    0.763267, 0.850242, 0.951554 ,
    0.765006, 0.856178, 0.950625 ,
    0.767001, 0.861997, 0.949624 ,
    0.769255, 0.867695, 0.948567 ,
    0.771766, 0.873270, 0.947467 ,
    0.774535, 0.878718, 0.946340 ,
    0.777561, 0.884039, 0.945201 ,
    0.780841, 0.889230, 0.944063 ,
    0.784374, 0.894289, 0.942942 ,
    0.788156, 0.899216, 0.941853 ,
    0.792184, 0.904010, 0.940809 ,
    0.796453, 0.908669, 0.939825 ,
    0.800958, 0.913194, 0.938916 ,
    0.805694, 0.917586, 0.938095 ,
    0.810654, 0.921845, 0.937376 ,
    0.815832, 0.925971, 0.936772 ,
    0.821221, 0.929967, 0.936297 ,
    0.826811, 0.933833, 0.935962 ,
    0.832595, 0.937572, 0.935781 ,
    0.838565, 0.941187, 0.935766 ,
    0.844709, 0.944679, 0.935927 ,
    0.851018, 0.948053, 0.936275 ,
    0.857482, 0.951311, 0.936822 ,
    0.864090, 0.954457, 0.937578 ,
    0.870830, 0.957495, 0.938550 ,
    0.877690, 0.960430, 0.939749 ,
    0.884659, 0.963266, 0.941183 ,
    0.891723, 0.966009, 0.942858 ,
    0.898871, 0.968662, 0.944783 ,
    0.906088, 0.971233, 0.946962 ,
    0.913362, 0.973726, 0.949402 ,
    0.920679, 0.976147, 0.952108 ,
    0.928026, 0.978504, 0.955083 ,
    0.935387, 0.980802, 0.958331 ,
    0.942750, 0.983048, 0.961854 ,
    0.950101, 0.985249, 0.965654 ,
    0.957424, 0.987412, 0.969733 ,
    0.964706, 0.989543, 0.974090 ,
    0.971932, 0.991652, 0.978724 ,
    0.979088, 0.993744, 0.983635 ,
    0.986161, 0.995828, 0.988820 ,
    0.993136, 0.997910, 0.994276 ,
    1.000000, 1.000000, 1.000000 ,
};

float colormap_parula[256 * 3] = {
    0.2081, 0.1663, 0.5292 ,
    0.2091, 0.1721, 0.5411 ,
    0.2101, 0.1779, 0.553   ,
    0.2109, 0.1837, 0.565   ,
    0.2116, 0.1895, 0.5771 ,
    0.2121, 0.1954, 0.5892 ,
    0.2124, 0.2013, 0.6013 ,
    0.2125, 0.2072, 0.6135 ,
    0.2123, 0.2132, 0.6258 ,
    0.2118, 0.2192, 0.6381 ,
    0.2111, 0.2253, 0.6505 ,
    0.2099, 0.2315, 0.6629 ,
    0.2084, 0.2377, 0.6753 ,
    0.2063, 0.244, 0.6878   ,
    0.2038, 0.2503, 0.7003 ,
    0.2006, 0.2568, 0.7129 ,
    0.1968, 0.2632, 0.7255 ,
    0.1921, 0.2698, 0.7381 ,
    0.1867, 0.2764, 0.7507 ,
    0.1802, 0.2832, 0.7634 ,
    0.1728, 0.2902, 0.7762 ,
    0.1641, 0.2975, 0.789   ,
    0.1541, 0.3052, 0.8017 ,
    0.1427, 0.3132, 0.8145 ,
    0.1295, 0.3217, 0.8269 ,
    0.1147, 0.3306, 0.8387 ,
    0.0986, 0.3397, 0.8495 ,
    0.0816, 0.3486, 0.8588 ,
    0.0646, 0.3572, 0.8664 ,
    0.0482, 0.3651, 0.8722 ,
    0.0329, 0.3724, 0.8765 ,
    0.0213, 0.3792, 0.8796 ,
    0.0136, 0.3853, 0.8815 ,
    0.0086, 0.3911, 0.8827 ,
    0.006,  0.3965, 0.8833 ,
    0.0051, 0.4017, 0.8834 ,
    0.0054, 0.4066, 0.8831 ,
    0.0067, 0.4113, 0.8825 ,
    0.0089, 0.4159, 0.8816 ,
    0.0116, 0.4203, 0.8805 ,
    0.0148, 0.4246, 0.8793 ,
    0.0184, 0.4288, 0.8779 ,
    0.0223, 0.4329, 0.8763 ,
    0.0264, 0.437, 0.8747   ,
    0.0306, 0.441, 0.8729   ,
    0.0349, 0.4449, 0.8711 ,
    0.0394, 0.4488, 0.8692 ,
    0.0437, 0.4526, 0.8672 ,
    0.0477, 0.4564, 0.8652 ,
    0.0514, 0.4602, 0.8632 ,
    0.0549, 0.464, 0.8611   ,
    0.0582, 0.4677, 0.8589 ,
    0.0612, 0.4714, 0.8568 ,
    0.064,  0.4751, 0.8546 ,
    0.0666, 0.4788, 0.8525 ,
    0.0689, 0.4825, 0.8503 ,
    0.071,  0.4862, 0.8481 ,
    0.0729, 0.4899, 0.846   ,
    0.0746, 0.4937, 0.8439 ,
    0.0761, 0.4974, 0.8418 ,
    0.0773, 0.5012, 0.8398 ,
    0.0782, 0.5051, 0.8378 ,
    0.0789, 0.5089, 0.8359 ,
    0.0794, 0.5129, 0.8341 ,
    0.0795, 0.5169, 0.8324 ,
    0.0793, 0.521, 0.8308   ,
    0.0788, 0.5251, 0.8293 ,
    0.0778, 0.5295, 0.828   ,
    0.0764, 0.5339, 0.827   ,
    0.0746, 0.5384, 0.8261 ,
    0.0724, 0.5431, 0.8253 ,
    0.0698, 0.5479, 0.8247 ,
    0.0668, 0.5527, 0.8243 ,
    0.0636, 0.5577, 0.8239 ,
    0.06,   0.5627, 0.8237 ,
    0.0562, 0.5677, 0.8234 ,
    0.0523, 0.5727, 0.8231 ,
    0.0484, 0.5777, 0.8228 ,
    0.0445, 0.5826, 0.8223 ,
    0.0408, 0.5874, 0.8217 ,
    0.0372, 0.5922, 0.8209 ,
    0.0342, 0.5968, 0.8198 ,
    0.0317, 0.6012, 0.8186 ,
    0.0296, 0.6055, 0.8171 ,
    0.0279, 0.6097, 0.8154 ,
    0.0265, 0.6137, 0.8135 ,
    0.0255, 0.6176, 0.8114 ,
    0.0248, 0.6214, 0.8091 ,
    0.0243, 0.625, 0.8066   ,
    0.0239, 0.6285, 0.8039 ,
    0.0237, 0.6319, 0.801   ,
    0.0235, 0.6352, 0.798   ,
    0.0233, 0.6384, 0.7948 ,
    0.0231, 0.6415, 0.7916 ,
    0.023,  0.6445, 0.7881 ,
    0.0229, 0.6474, 0.7846 ,
    0.0227, 0.6503, 0.781,
    0.0227, 0.6531, 0.7773 ,
    0.0232, 0.6558, 0.7735 ,
    0.0238, 0.6585, 0.7696 ,
    0.0246, 0.6611, 0.7656 ,
    0.0263, 0.6637, 0.7615 ,
    0.0282, 0.6663, 0.7574 ,
    0.0306, 0.6688, 0.7532 ,
    0.0338, 0.6712, 0.749   ,
    0.0373, 0.6737, 0.7446 ,
    0.0418, 0.6761, 0.7402 ,
    0.0467, 0.6784, 0.7358 ,
    0.0516, 0.6808, 0.7313 ,
    0.0574, 0.6831, 0.7267 ,
    0.0629, 0.6854, 0.7221 ,
    0.0692, 0.6877, 0.7173 ,
    0.0755, 0.6899, 0.7126 ,
    0.082,  0.6921, 0.7078 ,
    0.0889, 0.6943, 0.7029 ,
    0.0956, 0.6965, 0.6979 ,
    0.1031, 0.6986, 0.6929 ,
    0.1104, 0.7007, 0.6878 ,
    0.118,  0.7028, 0.6827 ,
    0.1258, 0.7049, 0.6775 ,
    0.1335, 0.7069, 0.6723 ,
    0.1418, 0.7089, 0.6669 ,
    0.1499, 0.7109, 0.6616 ,
    0.1585, 0.7129, 0.6561 ,
    0.1671, 0.7148, 0.6507 ,
    0.1758, 0.7168, 0.6451 ,
    0.1849, 0.7186, 0.6395 ,
    0.1938, 0.7205, 0.6338 ,
    0.2033, 0.7223, 0.6281 ,
    0.2128, 0.7241, 0.6223 ,
    0.2224, 0.7259, 0.6165 ,
    0.2324, 0.7275, 0.6107 ,
    0.2423, 0.7292, 0.6048 ,
    0.2527, 0.7308, 0.5988 ,
    0.2631, 0.7324, 0.5929 ,
    0.2735, 0.7339, 0.5869 ,
    0.2845, 0.7354, 0.5809 ,
    0.2953, 0.7368, 0.5749 ,
    0.3064, 0.7381, 0.5689 ,
    0.3177, 0.7394, 0.563   ,
    0.3289, 0.7406, 0.557   ,
    0.3405, 0.7417, 0.5512 ,
    0.352,  0.7428, 0.5453 ,
    0.3635, 0.7438, 0.5396 ,
    0.3753, 0.7446, 0.5339 ,
    0.3869, 0.7454, 0.5283 ,
    0.3986, 0.7461, 0.5229 ,
    0.4103, 0.7467, 0.5175 ,
    0.4218, 0.7473, 0.5123 ,
    0.4334, 0.7477, 0.5072 ,
    0.4447, 0.7482, 0.5021 ,
    0.4561, 0.7485, 0.4972 ,
    0.4672, 0.7487, 0.4924 ,
    0.4783, 0.7489, 0.4877 ,
    0.4892, 0.7491, 0.4831 ,
    0.5,    0.7491, 0.4786 ,
    0.5106, 0.7492, 0.4741 ,
    0.5212, 0.7492, 0.4698 ,
    0.5315, 0.7491, 0.4655 ,
    0.5418, 0.749, 0.4613   ,
    0.5519, 0.7489, 0.4571 ,
    0.5619, 0.7487, 0.4531 ,
    0.5718, 0.7485, 0.449   ,
    0.5816, 0.7482, 0.4451 ,
    0.5913, 0.7479, 0.4412 ,
    0.6009, 0.7476, 0.4374 ,
    0.6103, 0.7473, 0.4335 ,
    0.6197, 0.7469, 0.4298 ,
    0.629,  0.7465, 0.4261 ,
    0.6382, 0.746, 0.4224   ,
    0.6473, 0.7456, 0.4188 ,
    0.6564, 0.7451, 0.4152 ,
    0.6653, 0.7446, 0.4116 ,
    0.6742, 0.7441, 0.4081 ,
    0.683,  0.7435, 0.4046 ,
    0.6918, 0.743, 0.4011   ,
    0.7004, 0.7424, 0.3976 ,
    0.7091, 0.7418, 0.3942 ,
    0.7176, 0.7412, 0.3908 ,
    0.7261, 0.7405, 0.3874 ,
    0.7346, 0.7399, 0.384   ,
    0.743,  0.7392, 0.3806 ,
    0.7513, 0.7385, 0.3773 ,
    0.7596, 0.7378, 0.3739 ,
    0.7679, 0.7372, 0.3706 ,
    0.7761, 0.7364, 0.3673 ,
    0.7843, 0.7357, 0.3639 ,
    0.7924, 0.735, 0.3606   ,
    0.8005, 0.7343, 0.3573 ,
    0.8085, 0.7336, 0.3539 ,
    0.8166, 0.7329, 0.3506 ,
    0.8246, 0.7322, 0.3472 ,
    0.8325, 0.7315, 0.3438 ,
    0.8405, 0.7308, 0.3404 ,
    0.8484, 0.7301, 0.337   ,
    0.8563, 0.7294, 0.3336 ,
    0.8642, 0.7288, 0.33    ,
    0.872,  0.7282, 0.3265 ,
    0.8798, 0.7276, 0.3229 ,
    0.8877, 0.7271, 0.3193 ,
    0.8954, 0.7266, 0.3156 ,
    0.9032, 0.7262, 0.3117 ,
    0.911,  0.7259, 0.3078 ,
    0.9187, 0.7256, 0.3038 ,
    0.9264, 0.7256, 0.2996 ,
    0.9341, 0.7256, 0.2953 ,
    0.9417, 0.7259, 0.2907 ,
    0.9493, 0.7264, 0.2859 ,
    0.9567, 0.7273, 0.2808 ,
    0.9639, 0.7285, 0.2754 ,
    0.9708, 0.7303, 0.2696 ,
    0.9773, 0.7326, 0.2634 ,
    0.9831, 0.7355, 0.257   ,
    0.9882, 0.739, 0.2504   ,
    0.9922, 0.7431, 0.2437 ,
    0.9952, 0.7476, 0.2373 ,
    0.9973, 0.7524, 0.231   ,
    0.9986, 0.7573, 0.2251 ,
    0.9991, 0.7624, 0.2195 ,
    0.999,  0.7675, 0.2141 ,
    0.9985, 0.7726, 0.209   ,
    0.9976, 0.7778, 0.2042 ,
    0.9964, 0.7829, 0.1995 ,
    0.995,  0.788, 0.1949   ,
    0.9933, 0.7931, 0.1905 ,
    0.9914, 0.7981, 0.1863 ,
    0.9894, 0.8032, 0.1821 ,
    0.9873, 0.8083, 0.178   ,
    0.9851, 0.8133, 0.174   ,
    0.9828, 0.8184, 0.17    ,
    0.9805, 0.8235, 0.1661 ,
    0.9782, 0.8286, 0.1622 ,
    0.9759, 0.8337, 0.1583 ,
    0.9736, 0.8389, 0.1544 ,
    0.9713, 0.8441, 0.1505 ,
    0.9692, 0.8494, 0.1465 ,
    0.9672, 0.8548, 0.1425 ,
    0.9654, 0.8603, 0.1385 ,
    0.9638, 0.8659, 0.1343 ,
    0.9623, 0.8716, 0.1301 ,
    0.9611, 0.8774, 0.1258 ,
    0.96,   0.8834, 0.1215 ,
    0.9593, 0.8895, 0.1171 ,
    0.9588, 0.8958, 0.1126 ,
    0.9586, 0.9022, 0.1082 ,
    0.9587, 0.9088, 0.1036 ,
    0.9591, 0.9155, 0.099   ,
    0.9599, 0.9225, 0.0944 ,
    0.961,  0.9296, 0.0897 ,
    0.9624, 0.9368, 0.085   ,
    0.9641, 0.9443, 0.0802 ,
    0.9662, 0.9518, 0.0753 ,
    0.9685, 0.9595, 0.0703 ,
    0.971,  0.9673, 0.0651 ,
    0.9736, 0.9752, 0.0597 ,
    0.9763, 0.9831, 0.0538 ,
};

Canvas visualizer_to_canvas(Visualizer *v, char *name) {
    Canvas c = canvas_new(v->arr_len * (PIXEL + 1) + 1, v->arr_num * (PIXEL + 1) + 1, name);

    for (int i = 0; i <= v->arr_num * (PIXEL + 1); i++) {
        for (int j = 0; j <= v->arr_len * (PIXEL + 1); j++) {
            if (v->colors == BW) {
                c = canvas_set_rgb(c, j, i, 12, 133, 44);
            } else {
                c = canvas_set_rgb(c, j, i, 0, 0, 0);
            }
        }
    }

    for (int i = 0; i < v->arr_num; i++) {
        for (int j = 0; j < v->arr_len; j++) {
            for (int x = 0; x <= PIXEL; x++) {
                for (int y = 0; y <= PIXEL; y++) {
                    if (x != 0 && y != 0) {
                        if (v->colors == BW) {
                            c = canvas_set_grey(c, j * (PIXEL + 1) + x, i * (PIXEL + 1) + y, v->arrs[(v->arr_num - (i + 1)) * v->arr_len + j]);
                        } else if (v->colors == Virdis) {
                            c = canvas_set_r(c, j * (PIXEL + 1) + x, i * (PIXEL + 1) + y, colormap_virdis[3 * v->arrs[(v->arr_num - (i + 1)) * v->arr_len + j]]);
                            c = canvas_set_g(c, j * (PIXEL + 1) + x, i * (PIXEL + 1) + y, colormap_virdis[1 + 3 * v->arrs[(v->arr_num - (i + 1)) * v->arr_len + j]]);
                            c = canvas_set_b(c, j * (PIXEL + 1) + x, i * (PIXEL + 1) + y, colormap_virdis[2 + 3 * v->arrs[(v->arr_num - (i + 1)) * v->arr_len + j]]);
                        } else if (v->colors == Cubehelix) {
                            c = canvas_set_r(c, j * (PIXEL + 1) + x, i * (PIXEL + 1) + y, colormap_cubehelix[3 * v->arrs[(v->arr_num - (i + 1)) * v->arr_len + j]]);
                            c = canvas_set_g(c, j * (PIXEL + 1) + x, i * (PIXEL + 1) + y, colormap_cubehelix[1 + 3 * v->arrs[(v->arr_num - (i + 1)) * v->arr_len + j]]);
                            c = canvas_set_b(c, j * (PIXEL + 1) + x, i * (PIXEL + 1) + y, colormap_cubehelix[2 + 3 * v->arrs[(v->arr_num - (i + 1)) * v->arr_len + j]]);
                        } else if (v->colors == Inferno) {
                            c = canvas_set_r(c, j * (PIXEL + 1) + x, i * (PIXEL + 1) + y, colormap_inferno[3 * v->arrs[(v->arr_num - (i + 1)) * v->arr_len + j]]);
                            c = canvas_set_g(c, j * (PIXEL + 1) + x, i * (PIXEL + 1) + y, colormap_inferno[1 + 3 * v->arrs[(v->arr_num - (i + 1)) * v->arr_len + j]]);
                            c = canvas_set_b(c, j * (PIXEL + 1) + x, i * (PIXEL + 1) + y, colormap_inferno[2 + 3 * v->arrs[(v->arr_num - (i + 1)) * v->arr_len + j]]);
                        } else if (v->colors == Parula) {
                            c = canvas_set_r(c, j * (PIXEL + 1) + x, i * (PIXEL + 1) + y, colormap_parula[3 * v->arrs[(v->arr_num - (i + 1)) * v->arr_len + j]]);
                            c = canvas_set_g(c, j * (PIXEL + 1) + x, i * (PIXEL + 1) + y, colormap_parula[1 + 3 * v->arrs[(v->arr_num - (i + 1)) * v->arr_len + j]]);
                            c = canvas_set_b(c, j * (PIXEL + 1) + x, i * (PIXEL + 1) + y, colormap_parula[2 + 3 * v->arrs[(v->arr_num - (i + 1)) * v->arr_len + j]]);
                        }
                    }
                }
            }
        }
    }

    return c;
}

void free_visualizer(Visualizer v) {
    free(v.arrs);
}

#endif