/*
 * link `target/x86_64-pc-windows-gnu/debug/deps/xpsprint.o`.
 */
extern crate windows_result;
extern crate windows_strings;

use windows_result::*;
use windows_strings::*;

const S_OK: HRESULT = HRESULT(0);

#[no_mangle]
pub extern "C" fn StartXpsPrintJob(
    printer_name: /*L*/PCWSTR, // 32bit ptr variant not in crate yet.
    _job_name:          PCWSTR,
    _output_filename:   PCWSTR,
    // other args we don't care about.
) -> HRESULT {
    // https://learn.microsoft.com/en-us/windows/win32/api/xpsprint/nf-xpsprint-startxpsprintjob
    unsafe {
        println!("{:?}", printer_name.to_string());
    };
    S_OK
}
