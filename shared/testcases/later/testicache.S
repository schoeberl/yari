/*
 * Test the I$ by running through a bunch of simple ops in line.
 */

#define FAILURE la $2, .; mtlo $2; .word 0x48000000
#define SUCCESS li $2, 0x87654321; mtlo $2; .word 0x48000000
	.text
	.global	_start
	.ent	_start
_start:
	.set noreorder
	li $2,1
	li $2,2
	li $2,3
	li $2,4
	li $2,5
	li $2,6
	li $2,7
	li $2,8
	li $2,9
	li $2,10
	li $2,11
	li $2,12
	li $2,13
	li $2,14
	li $2,15
	li $2,16
	li $2,17
	li $2,18
	li $2,19
	li $2,20
	li $2,21
	li $2,22
	li $2,23
	li $2,24
	li $2,25
	li $2,26
	li $2,27
	li $2,28
	li $2,29
	li $2,30
	li $2,31
	li $2,32
	li $2,33
	li $2,34
	li $2,35
	li $2,36
	li $2,37
	li $2,38
	li $2,39
	li $2,40
	li $2,41
	li $2,42
	li $2,43
	li $2,44
	li $2,45
	li $2,46
	li $2,47
	li $2,48
	li $2,49
	li $2,50
	li $2,51
	li $2,52
	li $2,53
	li $2,54
	li $2,55
	li $2,56
	li $2,57
	li $2,58
	li $2,59
	li $2,60
	li $2,61
	li $2,62
	li $2,63
	li $2,64
	li $2,65
	li $2,66
	li $2,67
	li $2,68
	li $2,69
	li $2,70
	li $2,71
	li $2,72
	li $2,73
	li $2,74
	li $2,75
	li $2,76
	li $2,77
	li $2,78
	li $2,79
	li $2,80
	li $2,81
	li $2,82
	li $2,83
	li $2,84
	li $2,85
	li $2,86
	li $2,87
	li $2,88
	li $2,89
	li $2,90
	li $2,91
	li $2,92
	li $2,93
	li $2,94
	li $2,95
	li $2,96
	li $2,97
	li $2,98
	li $2,99
	li $2,100
	li $2,101
	li $2,102
	li $2,103
	li $2,104
	li $2,105
	li $2,106
	li $2,107
	li $2,108
	li $2,109
	li $2,110
	li $2,111
	li $2,112
	li $2,113
	li $2,114
	li $2,115
	li $2,116
	li $2,117
	li $2,118
	li $2,119
	li $2,120
	li $2,121
	li $2,122
	li $2,123
	li $2,124
	li $2,125
	li $2,126
	li $2,127
	li $2,128
	li $2,129
	li $2,130
	li $2,131
	li $2,132
	li $2,133
	li $2,134
	li $2,135
	li $2,136
	li $2,137
	li $2,138
	li $2,139
	li $2,140
	li $2,141
	li $2,142
	li $2,143
	li $2,144
	li $2,145
	li $2,146
	li $2,147
	li $2,148
	li $2,149
	li $2,150
	li $2,151
	li $2,152
	li $2,153
	li $2,154
	li $2,155
	li $2,156
	li $2,157
	li $2,158
	li $2,159
	li $2,160
	li $2,161
	li $2,162
	li $2,163
	li $2,164
	li $2,165
	li $2,166
	li $2,167
	li $2,168
	li $2,169
	li $2,170
	li $2,171
	li $2,172
	li $2,173
	li $2,174
	li $2,175
	li $2,176
	li $2,177
	li $2,178
	li $2,179
	li $2,180
	li $2,181
	li $2,182
	li $2,183
	li $2,184
	li $2,185
	li $2,186
	li $2,187
	li $2,188
	li $2,189
	li $2,190
	li $2,191
	li $2,192
	li $2,193
	li $2,194
	li $2,195
	li $2,196
	li $2,197
	li $2,198
	li $2,199
	li $2,200
	li $2,201
	li $2,202
	li $2,203
	li $2,204
	li $2,205
	li $2,206
	li $2,207
	li $2,208
	li $2,209
	li $2,210
	li $2,211
	li $2,212
	li $2,213
	li $2,214
	li $2,215
	li $2,216
	li $2,217
	li $2,218
	li $2,219
	li $2,220
	li $2,221
	li $2,222
	li $2,223
	li $2,224
	li $2,225
	li $2,226
	li $2,227
	li $2,228
	li $2,229
	li $2,230
	li $2,231
	li $2,232
	li $2,233
	li $2,234
	li $2,235
	li $2,236
	li $2,237
	li $2,238
	li $2,239
	li $2,240
	li $2,241
	li $2,242
	li $2,243
	li $2,244
	li $2,245
	li $2,246
	li $2,247
	li $2,248
	li $2,249
	li $2,250
	li $2,251
	li $2,252
	li $2,253
	li $2,254
	li $2,255
	li $2,256
	li $2,257
	li $2,258
	li $2,259
	li $2,260
	li $2,261
	li $2,262
	li $2,263
	li $2,264
	li $2,265
	li $2,266
	li $2,267
	li $2,268
	li $2,269
	li $2,270
	li $2,271
	li $2,272
	li $2,273
	li $2,274
	li $2,275
	li $2,276
	li $2,277
	li $2,278
	li $2,279
	li $2,280
	li $2,281
	li $2,282
	li $2,283
	li $2,284
	li $2,285
	li $2,286
	li $2,287
	li $2,288
	li $2,289
	li $2,290
	li $2,291
	li $2,292
	li $2,293
	li $2,294
	li $2,295
	li $2,296
	li $2,297
	li $2,298
	li $2,299
	SUCCESS
	.end	_start
