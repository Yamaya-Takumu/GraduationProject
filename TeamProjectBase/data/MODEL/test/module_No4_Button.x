xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 31;
 0.02374;20.11390;1.38457;,
 -5.47047;18.56836;-0.92224;,
 -7.74624;18.56836;1.38457;,
 0.02374;20.11390;1.38457;,
 0.02374;18.56836;-1.87775;,
 -10.12823;14.16701;-2.87783;,
 -14.33333;14.16701;1.38457;,
 0.02374;14.16701;-4.64338;,
 -13.24046;7.57993;-4.18451;,
 -18.73466;7.57993;1.38457;,
 0.02374;7.57993;-6.49134;,
 -14.33333;-0.19006;-4.64338;,
 -20.28022;-0.19006;1.38457;,
 0.30438;-0.34118;-7.14648;,
 0.30438;-0.34118;-7.14648;,
 -20.28022;-0.19006;1.38457;,
 -14.33333;-0.19006;-4.64338;,
 -0.39848;-0.36593;1.41577;,
 -13.24046;7.57993;-4.18451;,
 0.32348;7.47226;1.37626;,
 -18.73466;7.57993;1.38457;,
 -10.12823;14.16701;-2.87783;,
 -0.38501;11.47819;1.09207;,
 -14.33333;14.16701;1.38457;,
 0.02374;14.16701;-4.64338;,
 0.02374;7.57993;-6.49134;,
 -5.47047;18.56836;-0.92224;,
 0.01276;16.34320;1.42510;,
 -7.74624;18.56836;1.38457;,
 0.02374;18.56836;-1.87775;,
 0.02374;20.11390;1.38457;;
 
 31;
 3;0,1,2;,
 3;3,4,1;,
 4;2,1,5,6;,
 4;1,4,7,5;,
 4;6,5,8,9;,
 4;5,7,10,8;,
 4;9,8,11,12;,
 4;8,10,13,11;,
 3;14,15,16;,
 3;14,17,15;,
 3;18,19,20;,
 3;21,22,23;,
 3;24,22,21;,
 3;25,19,18;,
 3;25,17,14;,
 3;17,20,15;,
 3;24,19,25;,
 3;19,23,20;,
 3;19,17,25;,
 3;17,19,20;,
 3;26,27,28;,
 3;29,27,26;,
 3;29,22,24;,
 3;22,28,23;,
 3;22,19,24;,
 3;19,22,23;,
 3;30,27,26;,
 3;30,27,29;,
 3;27,30,28;,
 3;27,22,29;,
 3;22,27,28;;
 
 MeshMaterialList {
  5;
  31;
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4;;
  Material {
   0.511200;0.448800;0.473600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.476800;0.740000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.367200;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.228800;0.228800;0.228800;0.450000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.119216;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  44;
  -0.134164;0.940934;-0.310875;,
  -0.114562;0.743606;-0.658731;,
  -0.349451;0.871223;-0.344751;,
  -0.237802;0.825524;-0.511821;,
  -0.157004;0.400435;-0.902774;,
  -0.574998;0.589564;-0.567266;,
  -0.380941;0.515925;-0.767271;,
  -0.167850;0.173178;-0.970482;,
  -0.681676;0.288181;-0.672510;,
  -0.444703;0.241808;-0.862420;,
  -0.169019;0.078371;-0.982492;,
  -0.704845;0.140204;-0.695368;,
  -0.458873;0.114775;-0.881058;,
  -0.008839;-0.999954;-0.003616;,
  -0.004008;-0.999946;-0.009585;,
  -0.133305;-0.941235;-0.310333;,
  -0.183709;-0.890898;-0.415394;,
  -0.010628;-0.999912;-0.007933;,
  -0.012417;-0.999848;-0.012250;,
  -0.005652;-0.999968;-0.005576;,
  -0.189723;-0.963832;-0.187172;,
  -0.074372;-0.900884;-0.427641;,
  -0.002364;-0.999905;-0.013594;,
  0.999844;-0.017614;0.001596;,
  0.999265;-0.031776;0.021427;,
  0.996235;0.028525;0.081861;,
  -0.000551;0.002655;0.999996;,
  -0.000222;0.001673;0.999999;,
  -0.001566;0.000312;0.999999;,
  0.996906;0.053344;0.057724;,
  0.999072;0.034197;0.026200;,
  0.012222;0.027258;0.999554;,
  0.017499;0.017474;0.999694;,
  -0.264835;-0.928224;-0.261272;,
  -0.096754;-0.825305;-0.556337;,
  0.999254;-0.038539;0.002351;,
  0.998259;0.023618;0.054050;,
  0.009281;-0.004557;0.999947;,
  -0.003367;-0.026649;0.999639;,
  0.389738;-0.011032;-0.920860;,
  0.999995;-0.002898;0.001373;,
  0.998892;-0.040511;-0.023971;,
  -0.013192;-0.027797;0.999527;,
  -0.002139;0.010753;0.999940;;
  31;
  3;0,3,2;,
  3;0,1,3;,
  4;2,3,6,5;,
  4;3,1,4,6;,
  4;5,6,9,8;,
  4;6,4,7,9;,
  4;8,9,12,11;,
  4;9,7,10,12;,
  3;17,17,18;,
  3;17,13,17;,
  3;14,14,19;,
  3;15,15,20;,
  3;21,15,15;,
  3;22,14,14;,
  3;23,24,25;,
  3;26,27,28;,
  3;29,30,23;,
  3;31,32,27;,
  3;30,24,23;,
  3;26,31,27;,
  3;16,16,33;,
  3;34,16,16;,
  3;35,36,29;,
  3;37,38,32;,
  3;36,30,29;,
  3;31,37,32;,
  3;39,39,39;,
  3;40,41,35;,
  3;42,43,38;,
  3;41,36,35;,
  3;37,42,38;;
 }
 MeshTextureCoords {
  31;
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.750000;0.125000;,
  0.937500;0.000000;,
  1.000000;0.125000;,
  0.875000;0.250000;,
  0.750000;0.250000;,
  1.000000;0.250000;,
  0.875000;0.375000;,
  0.750000;0.375000;,
  1.000000;0.375000;,
  0.875000;0.500000;,
  0.750000;0.500000;,
  1.000000;0.500000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;;
 }
}