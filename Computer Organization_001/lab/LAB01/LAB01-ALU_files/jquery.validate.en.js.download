/*
 * Translated default messages for the jQuery validation plugin.
 * Locale: KO
 */
jQuery.extend(jQuery.validator.messages, {
		required: "This field is required.",
		remote: "Please fix this field.",
		email: "Please enter a valid email address.",
		url: "Please enter a valid URL.",
		date: "Please enter a valid date.",
		dateISO: "Please enter a valid date ( ISO ).",
		number: "Please enter a valid number.",
		digits: "Please enter only digits.",
		creditcard: "Please enter a valid credit card number.",
		equalTo: "Please enter the same value again.",
		maxlength: $.validator.format( "Please enter no more than {0} characters." ),
		minlength: $.validator.format( "Please enter at least {0} characters." ),
		rangelength: $.validator.format( "Please enter a value between {0} and {1} characters long." ),
		range: $.validator.format( "Please enter a value between {0} and {1}." ),
		max: $.validator.format( "Please enter a value less than or equal to {0}." ),
		min: $.validator.format( "Please enter a value greater than or equal to {0}." )
});

/* 경고창으로 띄우기 */
jQuery.validator.setDefaults({
	onkeyup:false,
	onclick:false,
	onfocusout:false,
	showErrors:function(errorMap, errorList){
		if($(errorList).length > 0)
		{		  
			var caption = $(errorList[0].element).attr('placeholder') || $(errorList[0].element).attr('alt') || $(errorList[0].element).attr('name');
			alert('[' + caption + ']' + errorList[0].message);
		}
	}
});
/*
$.validator.addMethod("password", function( value, element ) {
	var result = this.optional(element) || value.length >= 6 && /\d/.test(value) && /[a-z]/i.test(value);
	if (!result) {
		element.value = "";
		var validator = this;
		setTimeout(function() {
			validator.blockFocusCleanup = true;
			element.focus();
			validator.blockFocusCleanup = false;
		}, 1);
	}
	return result;
}, "비밀번호는 최소 6자리 숫자, 알파벳 혼합으로 입력하셔야 합니다.");
*/
$.validator.addMethod("userid", function( value, element ) {
	var result = this.optional(element) || /[a-z0-9_]{4,12}/i.test(value);
	if (!result) {
		element.value = "";
		var validator = this;
		setTimeout(function() {
			validator.blockFocusCleanup = true;
			element.focus();
			validator.blockFocusCleanup = false;
		}, 1);
	}
	return result;
}, "아이디는 4~12자 숫자, 영문으로만 입력 가능합니다.");